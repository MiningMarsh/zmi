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
	if(verbose_Debug)
		printf("Reverting IO modes...\n");
	// Revert input.
	cleanin();
	// Revert output.
	cleanout();
	if(verbose_Debug)
		printf("Cleaning RAM...\n");
	// Free the storyfile from ram.
	free(RAM);
	// Print a stacktrace in debug mode.
	if(verbose_Debug >= 6)
		stacktrace();
	while(current_frame->old_frame != NULL) {
		if(verbose_Debug)
			printf("Cleaning frame...\n");
		popframe();
	}
	// Pop the final frame manually. (popframe() wont let us.)
	if(verbose_Debug)
		printf("Cleaning final frame...\n");
	free(current_frame->locals);
	free(current_frame->stack);
	free(current_frame);
}
