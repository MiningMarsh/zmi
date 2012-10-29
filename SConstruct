#imports
import sys, os
#source directories 
sources = Glob("src/*.c")

#include directories
incdirs=["src","include"]

#options
AddOption("--gdb", dest="debug", action='store_true', default=False, help="Compile a debug release")
AddOption("--fast", dest="fast", action='store_true', default=False, help="Compile for speed")
AddOption("--small", dest="small", action='store_true', default=False, help="Compile for a small executable")

#env initialization
env = Environment()

#env setup
env.Append(CCFLAGS='-pipe -fomit-frame-pointer --std=c99')
env.Append(CPPPATH=incdirs)
zmi = env.Program('build/zmi', sources)

#option reading
if(GetOption("debug")):
	env.Append(CCFLAGS='-ggdb')
if(env.GetOption('clean')):
	os.system("touch src/* ; touch include/* ; touch SConstruct")
	os.system("rm src/*.d 2>/dev/null")
	os.system("rm build/* 2>/dev/null")
if(GetOption("small")):
	env.Append(CCFLAGS='-Os')
if(GetOption("fast")):
	env.Append(CCFLAGS='-O9')
#compile
#install
env.Install("/usr/bin",zmi)

#aliases
env.Alias('install',['/usr/bin'])
