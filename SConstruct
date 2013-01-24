#imports
import sys, os, fnmatch, shutil
#env initialization
env = Environment(
		CCCOMSTR='\r[COMPILE] $SOURCES',
		LINKCOMSTR='\r[LINK] $TARGET'
	)

HeaderDirectory = "include"
SourceDirectory = "src"
SourceExtensions = ["c", "cpp"]
DefaultVariant = "generic"
BuildPrefix = "build/objects"

# Compile flags.
Flags = '--std=c99 -pipe'

#options
AddOption(
	'--debugging', 
	dest='debug', 
	action='store_true', 
	default=False, 
	help='Compile a debug release'
)

AddOption('--strict', 
	dest='strict', 
	action='store_true', 
	default=False, 
	help='Stop compiling whenever the compiler issues a warning.'
)

AddOption(
	'--fast', 
	dest='fast', 
	action='store_true', 
	default=False, 
	help='Compile a fast executable'
)

AddOption(
	'--small', 
	dest='small', 
	action='store_true', 
	default=False, 
	help='Compile a small executable'
)

AddOption(
	'--tool-prefix', 
	dest='tool-prefix', 
	type='string', 
	nargs=1, 
	action='store', 
	metavar='TOOL', 
	help='tool prefix'

)
AddOption(
	'--mingw32', 
	dest='mingw32', 
	action='store_true', 
	default=False, 
	help='Cross compile for windows'
)

Variant = DefaultVariant

if(GetOption('mingw32')):
	env.Append(CCFLAGS='-mwindows')
	Libraries = ['mingw32']
	Variant = 'windows'
	Executable = 'out.exe'
else:
	Libraries = []
	Executable = 'out'
	Variant = 'linux'

BuildPrefix = BuildPrefix + '/' + Variant

#source directories
env.VariantDir(BuildPrefix, SourceDirectory, duplicate=0)
Sources = []
for Extension in SourceExtensions:
	for Root, Directories, Files in os.walk(SourceDirectory):
		for Files in fnmatch.filter(Files, '*.' + Extension):
			Sources.append((os.path.join(Root, Files)).replace(SourceDirectory, BuildPrefix, 1))

Executable = 'build/' + Variant + '/' + Executable

# Include directories
Headers = [HeaderDirectory]

#env setup
env.Append(CCFLAGS=Flags)
env.Append(CPPPATH=Headers)
if(GetOption('tool-prefix')):
	env['CC']=GetOption('tool-prefix')+'-gcc'
	env['CXX']=GetOption('tool-prefix')+'-g++'
	env['LD']=GetOption('tool-prefix')+'-ld'
else:
	env['CC']='gcc'
	env['CXX']='g++'
	env['LD']='ld'

Install = env.Program(Executable, Sources, LIBS=Libraries)

#option reading
if(GetOption('debug')):
	env.Append(CCFLAGS='-ggdb -Wall -Wextra')
if(GetOption('strict')):
	env.Append(CCFLAGS='-Werror')
if(GetOption('small')):
	env.Append(CCFLAGS='-Os')
if(GetOption('fast')):
	env.Append(CCFLAGS='-O3')
if env.GetOption('clean'):
	if os.path.isdir('build'):
		shutil.rmtree('build')


#install
env.Install('/usr/bin', Install)

#aliases
env.Alias('install',['/usr/bin'])
