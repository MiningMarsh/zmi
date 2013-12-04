#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
#include "log.h"

// Clean things instead of letting the OS do it.
void clean() {
	const char* const Prefix = "clean()";
	log_Message(MNull, "", "");
	log_Message(MNull, Prefix, "Begin cleanup.");

	if(VerboseDebug)
		log_Message(MNull, Prefix, "Reverting IO modes.");
	// Revert input.
	cleanInput();
	// Revert output.
	cleanOutput();
	
	if(VerboseDebug) {
		log_Message(MNull, Prefix, "Cleaning RAM.");
	}

	// Free the storyfile from ram.
	if(RAM) {
		free(RAM);
	}
	
	// Print a Stacktrace in debug mode.
	if(VerboseDebug >= 5) {
		traceZStack();
	}
	
	if(CurrentZFrame) {
		while(CurrentZFrame->OldFrame != NULL) {
			if(VerboseDebug)
				log_Message(MNull, Prefix, "Cleaning frame.");
			popZFrame();
		}
		// Pop the final frame manually. (popframe() wont let us.)
		if(VerboseDebug) {
			log_Message(MNull, Prefix, "Cleaning final frame.");
		}
		free(CurrentZFrame->Locals);
		free(CurrentZFrame->Stack);
		free(CurrentZFrame);
	}
	
	// Close the log file.
	log_Close();
	printf("\n");
}
