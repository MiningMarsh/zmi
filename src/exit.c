#include <stdlib.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
#include "log.h"
uint8_t* RAM;

// Clean things instead of letting the OS do it.
void clean() {
	const char* const Prefix = "clean()";
	logMessage(MNull, "", "");
	logMessage(MNull, Prefix, "Begin cleanup.");

	if(g_VerboseDebug)
		logMessage(MNull, Prefix, "Reverting IO modes.");
	// Revert input.
	cleanInput();
	// Revert output.
	cleanOutput();
	
	if(g_VerboseDebug)
		logMessage(MNull, Prefix, "Cleaning RAM.");
	// Free the storyfile from ram.
	if(RAM)
		free(RAM);
	
	// Print a Stacktrace in debug mode.
	if(g_VerboseDebug >= 5)
		traceZStack();
	
	if(CurrentZFrame) {
		while(CurrentZFrame->OldFrame != NULL) {
			if(g_VerboseDebug)
				logMessage(MNull, Prefix, "Cleaning frame.");
			popZFrame();
		}
		// Pop the final frame manually. (popframe() wont let us.)
		if(g_VerboseDebug)
			logMessage(MNull, Prefix, "Cleaning final frame.");
		free(CurrentZFrame->Locals);
		free(CurrentZFrame->Stack);
		free(CurrentZFrame);
	}
	
	// Close the log file.
	logClose();
}
