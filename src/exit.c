#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "memory.h"
uint8_t* RAM; // Holds the file.

void clean() {
	printf("Exiting...\n");
	printf("Reverting input modes...\n");
	cleanin();
	printf("Cleaning RAM...\n");
	free(RAM);
	stacktrace();
	while(current_frame->old_frame != NULL) {
		printf("Cleaning frame...\n");
		popframe();
	}
	printf("Cleaning final frame...\n");
	free(current_frame->locals);
	free(current_frame->stack);
	free(current_frame);
}
