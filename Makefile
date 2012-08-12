J=1
all:
	scons -j$(J)
clean:
	scons -c -j$(J)
