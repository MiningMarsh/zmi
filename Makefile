CC = gcc
LIBS=
STATLIBS=
INCLUDES = -Iinclude/ -Isrc/
INCDIR = include/
SRCDIR = src/
SRCEXT = c
SRCS = $(wildcard $(SRCDIR)*.$(SRCEXT))
EXE = zmi
FLAGS =
OFLAGS = -ggdb -c -MMD -MP -std=c99 -O9
OBJEND = .o

ifeq ($(LTYPE), static)
	LIBS=$(STATLIBS)
endif
ifeq ($(LTYPE), win32)
	EXE := $(EXE).exe
	FLAGS := $(FLAGS) -DWIN32
	CC = i586-mingw32msvc-gcc
	OBJEND = .wo
endif

OBJECTS = $(patsubst %.$(SRCEXT),%$(OBJEND),$(SRCS))
DEPS = $(patsubst %$(OBJEND),%.d,$(OBJECTS))
all: $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(FLAGS) -o$(EXE)
$(OBJECTS): %$(OBJEND): %.$(SRCEXT)
	$(CC) $(OFLAGS) $(INCLUDES) $< -o $@
	@sed -i -e '1s,\($*\)\.o[ :]*,\1.o $*.d: ,' $*.d
-include $(DEPS)
clean:
	touch src/*
	touch Makefile
	rm -f src/*.o src/*.d src/*.wo $(EXE) bin/$(EXE) *.zip
install:
	cp $(EXE) ~/bin/$(EXE)
