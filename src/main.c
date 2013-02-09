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
		while(*Value != 0 && *Value != '=')
			Value++;

		// seperate the key and value, but not if it is a filename.
		if(*Value != 0 && ArgType) {
			*Value = 0;	
			Value++;
		}

		// A lookup table mapping long options to flags.
		#define MaxLookupSize 20
		const char const LookupTable[][MaxLookupSize] = {
			"help","h",
			"string-indirection","i",
			"debug","d",
			"log-file","l"
		};
		int LookupTableSize = sizeof(LookupTable)/(sizeof(char)*MaxLookupSize);
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
				int LookupIndex = 0;
				// The table is null terminated.
				while(LookupIndex < LookupTableSize) {
					if(!strcmp(Key,LookupTable[LookupIndex])) {
						Flag = LookupTable[1+LookupIndex][0];
					}
					LookupIndex += 2;
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
					"MM's and Triclops200's Z-machine Interpreter.\n"
					"Version %i.%i\n"
					"Compliant with standard %i.%i\n"
					"Arguments take form as:  -<flag>=<value>\n"
					"                         --<key>=<value>\n"
					"Options:\n"
					"-i,--string-indirection  Show pointer indirection in Z-Strings by\n"
					"                         surrounding them like <this>.\n"
					"-h,--help                Display this message.\n"
					"-d,--debug=#             Set the verboseness.\n"
					"-l,--log=<file>          File to log interpretr messages to.\n"
					"                         Use 'err' to log to stderr.\n",
					d_VersionMajor,
					d_VersionMinor,
					d_StandardMajor,
					d_StandardMinor
				);
				exit(0);
				break;

			// Turn on debug messages.
			case 'd':
				g_VerboseDebug = atoi(Value);
				if(!g_VerboseDebug) {
					fputs("--debug expects a non-zero integer value.\n", stderr);
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
			"MM's and Triclops200's Z-machine Interpreter.\n"
			"Usage: %s <filename> [OPTS]\n",
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

