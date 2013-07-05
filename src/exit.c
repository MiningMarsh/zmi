#include <stdlib.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
#include "log.h"

// Clean things instead of letting the OS do it.
void clean() {
	const char* const Prefix = "clean()";
	logMessage(MNull, "", "");
	logMessage(MNull, Prefix, "Begin cleanup.");

	if(VerboseDebug)
		logMessage(MNull, Prefix, "Reverting IO modes.");
	// Revert input.
	cleanInput();
	// Revert output.
	cleanOutput();
	
	if(VerboseDebug) {
		logMessage(MNull, Prefix, "Cleaning RAM.");
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
				logMessage(MNull, Prefix, "Cleaning frame.");
			popZFrame();
		}
		// Pop the final frame manually. (popframe() wont let us.)
		if(VerboseDebug) {
			logMessage(MNull, Prefix, "Cleaning final frame.");
		}
		free(CurrentZFrame->Locals);
		free(CurrentZFrame->Stack);
		free(CurrentZFrame);
	}
	
	// Close the log file.
	logClose();
}
