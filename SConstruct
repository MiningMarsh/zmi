#imports
import sys, os

#source directories
sources = Glob("src/*.c")

#include directories
incdirs=["src","include"]

#options
AddOption("--gdb", dest="debug", action='store_true', default=False, help="Compile with gdb debug support")

#env initialization
env = Environment()

#env setup
env.Append(CCFLAGS='-O9 -std=c99')
env.Append(CPPPATH=incdirs)

#option reading
if(GetOption("debug")):
	env.Append(CCFLAGS='-ggdb')

#compile
env.Program('zmi', sources)
