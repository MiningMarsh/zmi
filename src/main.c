#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "command.h"
#include "globalvars.h"
#include "log.h"


int main(int ArgCount, char** Arguments) {

	// We need to grab these from the program arguments.
	char* Filename = NULL;
	
	// By default print no debug messages.
	g_VerboseDebug = 0;
	// Don't print <> around string pointers.
	g_StrIndirection = 0;
	// Don't be a pirate. Too bad, bein' a pirate of the seven seas
	// be for me. Yaaarrr!
	g_TripPiracy = false;

	g_ProgramName = Arguments[0];

	// Loop through all the arguments.
	int CurArg = 0;
	while(--ArgCount) {
		CurArg++;
		// The switch to set.
		char Flag = 0;
		// Holds everything after the '=' of the argument.
		char* Value = Arguments[CurArg];
		// Holds everything befor the '=' of the argument.
		char* Key = Arguments[CurArg];
		// The type of argument being passed (name, switch, or full).
		int ArgType = 0;

		// Get rid of the preceding '-'s
		while(*Key == '-') {
			Key++;
			// We tell the type by the amount of preceding '-'.
			ArgType++;
		}

		// Set the keys value to everything after the '='
		// if it exists. Otherwise the value is null.
		while(*Value && *Value != '=')
			Value++;

		// seperate the key and value, but not if it is a filename.
		if(*Value && ArgType) {
			*Value = 0;	
			Value++;
		}
		
		// Matches long options to flags.
		struct {
			const char Flag;
			const char* const LongOption;
		} Options[] = {
			{'h', "help"},
			{'i', "string-indirection"},
			{'d', "debug"},
			{'l',"log-file"},
			{'p',"piracy"},
			{0, NULL}
		};

		switch(ArgType) {
			// We are dealing with a flag.
			case 1:
				if(strlen(Key) != 1) {
					fputs("FATAL: Bad flag format: -", stderr);
					fputs(Key, stderr);
					fputs("\n", stderr);
					exit(1);
				}
				Flag = *Key;
				break;

			// We are dealing with a long option, an need to convert it
			// to a flag with the lookup table.
			case 2: {
				if(Key == Value) {
					if(ArgCount > 2 || ((ArgCount > 1) && Filename)) {
						fputs("FATAL: More then one filename passed.\n", stderr);
						exit(1);
					}
					Filename = Arguments[++CurArg];
					ArgCount = 1;
					continue;
				}
				
				// The table is null terminated.
				for(int LookupIndex = 0; Options[LookupIndex].LongOption != NULL; ++LookupIndex) {
					if(!strcmp(Key, Options[LookupIndex].LongOption)) {
						Flag = Options[LookupIndex].Flag;
					}
				}
				break; }

			// We are dealing with a filename.
			default:
				if(Filename) {
					fputs("FATAL: More then one filename passed.\n", stderr);
					exit(1);
				}
				Filename = Key;
				break;

		}
		switch(Flag) {
			// Print a help message.
			case 'h':
				printf(
					"MM's and Triclops200's Z-Machine Interpreter.\n"
					"Version %i.%i\n"
					"Compliant with standard %i.%i\n"
					"Arguments take form as:  -<flag>=<value>\n"
					"                         --<key>=<value>\n"
					"Options:\n"
					"-i,--string-indirection  Show pointer indirection in Z-Strings by\n"
					"                         surrounding them like <this>.\n"
					"-h,--help                Display this message. \n"
					"-d,--debug=#,max,off     Set the verboseness. (defualt: off)\n"
					"-l,--log=<file>          File to log interpreter messages to.\n"
					"                         Use 'stderr' to log to stderr.\n"
					"                         Use 'stdout' to log to stdout.\n"
					"-p,--piracy              Trip the piracy opcode. We be pirates!\n",
					d_VersionMajor,
					d_VersionMinor,
					d_StandardMajor,
					d_StandardMinor
				);
				exit(0);
				break;

			// Turn on debug messages.
			case 'd':
				if(!strcmp(Value, "max")) {
					g_VerboseDebug = ~0;
					break;
				}
				if(!strcmp(Value, "off")) {
					g_VerboseDebug = 0;
					break;
				}
				g_VerboseDebug = atoi(Value);
				if(!g_VerboseDebug) {
					fputs("--debug expects a non-zero integer value, the string 'max', or the string 'off'.\n", stderr);
					exit(1);
				}
				break;

			// Turn on string indirection printing.
			case 'i':
				g_StrIndirection = 1;
				break;

			// Open the log file
			case 'l':
				logOpen(Value);
				break;

			// Yaarr!
			case 'p':
				g_TripPiracy = true;
				break;

			// A bad flag has been passed.
			default:
				if(!ArgType)
					break;
				fputs("Unrecognized option: ",stderr);
				fputs(Arguments[CurArg] ,stderr);
				fputs("\n",stderr);
				exit(1);
				break;
		}
	}

	// Check if a filename was passed.
	if (!Filename) {
		printf(
			"Usage: %s <filename> [options]\n"
			"To see a list of options, use: %s --help\n",
			g_ProgramName,
			g_ProgramName
		);
		exit(1);
	}
	loadRAM(Filename);
	// Initialize the machine.
	initZM();
	fflush(stdout);
	// Execute each command. I intend to make execNextInstruction
	// recursive and make this loop obsolete.
	while(1)
		execNextInstruction();
}

