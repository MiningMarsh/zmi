#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
#include "log.h"
uint8_t* RAM; // Holds the file.

// Clean things instead of letting the OS do it.
void clean() {
	LogClose();
	printf("Exiting...\n");
	if(VerboseDebug)
		printf("Reverting IO modes...\n");
	// Revert input.
	cleanInput();
	// Revert output.
	cleanOutput();
	if(VerboseDebug)
		printf("Cleaning RAM...\n");
	// Free the storyfile from ram.
	free(RAM);
	// Print a Stacktrace in debug mode.
	if(VerboseDebug >= 6)
		traceZStack();
	while(CurrentZFrame->OldFrame != NULL) {
		if(VerboseDebug)
			printf("Cleaning frame...\n");
		popZFrame();
	}
	// Pop the final frame manually. (popframe() wont let us.)
	if(VerboseDebug)
		printf("Cleaning final frame...\n");
	free(CurrentZFrame->Locals);
	free(CurrentZFrame->Stack);
	free(CurrentZFrame);
}
