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
if(env.GetOption('clean')):
	print("touch src/* ; touch include/* ; touch SConstruct")
	os.system("touch src/* ; touch include/* ; touch SConstruct")
	print("rm src/*.d")
	os.system("rm src/*.d")
#compile
zmi = env.Program('build/zmi', sources)
#install
env.Install("/usr/bin",zmi)

#aliases
env.Alias('install',['/usr/bin'])
