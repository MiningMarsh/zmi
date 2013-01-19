#imports
import sys, os
#env initialization
env = Environment(
	CCCOMSTR="[CC] $SOURCES",
	LINKCOMSTR="[LD] $TARGET: $SOURCES"
	)
builddir= "generic"
# Compile flags.
flags='--std=c99 -pipe'

#options
AddOption('--debugging', dest='debug', action='store_true', default=False, help='Compile a debug release')
AddOption('--strict', dest='strict', action='store_true', default=False, help='Compile a debug release')
AddOption('--fast', dest='fast', action='store_true', default=False, help='Compile for speed')
AddOption('--small', dest='small', action='store_true', default=False, help='Compile for a small executable')
AddOption('--tool-prefix', dest='tool-prefix', type='string', nargs=1, action='store', metavar='TOOL', help='tool prefix')
AddOption('--mingw32', dest='mingw32', action='store_true', default=False, help='Cross compile for windows')

if(GetOption('mingw32')):
	env.Append(CCFLAGS='-mwindows')
	lib=['mingw32']
	variant='windows'
	exe='out.exe'
else:
	lib=[]
	exe= 'out'
	variant= 'linux'

#source directories
env.VariantDir('build/objects/'+variant,'src', duplicate=0)
sources = Glob("build/objects/" + variant + "/*.c")
exe="build/" + variant + "/" + exe

# Include directories
incdirs=["./include"]

#env setup
env.Append(CCFLAGS=flags)
env.Append(CPPPATH=incdirs)
if(GetOption('tool-prefix')):
	env['CC']=GetOption('tool-prefix')+'-gcc'
	env['CXX']=GetOption('tool-prefix')+'-g++'
	env['LD']=GetOption('tool-prefix')+'-ld'
else:
	env['CC']='gcc'
	env['CXX']='g++'
	env['LD']='ld'
	
zmi = env.Program(exe,sources,LIBS=lib)
#option reading
if(GetOption("debug")):
	env.Append(CCFLAGS='-ggdb -Wall -Wextra')
if(GetOption("strict")):
	env.Append(CCFLAGS='-Werror')
if(GetOption("small")):
	env.Append(CCFLAGS='-Os')
if(GetOption("fast")):
	env.Append(CCFLAGS='-O3')
#install
env.Install("/usr/bin",zmi)

#aliases
env.Alias('install',['/usr/bin'])
