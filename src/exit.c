#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
uint8_t* RAM; // Holds the file.

// Clean things instead of letting the OS do it.
void clean() {
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
	// Print a stacktrace in debug mode.
	if(VerboseDebug >= 6)
		traceZStack();
	while(CurrentZFrame->old_frame != NULL) {
		if(VerboseDebug)
			printf("Cleaning frame...\n");
		popZFrame();
	}
	// Pop the final frame manually. (popframe() wont let us.)
	if(VerboseDebug)
		printf("Cleaning final frame...\n");
	free(CurrentZFrame->locals);
	free(CurrentZFrame->stack);
	free(CurrentZFrame);
}
