OUTPUT = build/zmi

SILENT=@
PRINT=$(SILENT)echo
MKDIR=mkdir
RM=rm -r

# Build tools can be specified easier using TOOL-PREFIX.
CC:=$(TOOL-PREFIX)$(CC)
CXX:=$(TOOL-PREFIX)$(CXX)
LD:=$(TOOL-PREFIX)$(LD)

INCLUDE=-Iinclude -Isrc

BASEFLAGS=$(INCLUDE) -Wall -O2 -fno-omit-frame-pointer -pipe -ffast-math
CFLAGS=$(BASEFLAGS) -std=c99
CXXFLAGS=$(BASEFLAGS) 

OBJDIR=src/objects
SRCDIR=src
SRC=$(wildcard $(SRCDIR)/*.c)
HEADERS=$(wildcard include/*.h)
OBJECTS=${SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o}

all: $(OBJECTS) $(OUTPUT)

$(OUTPUT):
	$(PRINT) " * Linking $(OUTPUT)..."
	$(SILENT)$(CC) $(OBJECTS) -o $(OUTPUT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(PRINT) " * Compiling $< into $@..."
	$(SILENT)$(CC) -c -o $@ $(CFLAGS) $<

clean:
	$(SILENT)$(RM) $(OBJECTS) $(OUTPUT)

%.h:
