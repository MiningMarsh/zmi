#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "memory.h"
#include "globalvars.h"
uint8_t* RAM; // Holds the file.

void clean() {
	printf("Exiting...\n");
	if(verbose_Debug)
	printf("Reverting IO modes...\n");
	cleanin();
	cleanout();
	if(verbose_Debug)
	printf("Cleaning RAM...\n");
	free(RAM);
	if(verbose_Debug >= 6) {
		stacktrace();
		while(current_frame->old_frame != NULL) {
			printf("Cleaning frame...\n");
			popframe();
		}
		printf("Cleaning final frame...\n");
	}
	free(current_frame->locals);
	free(current_frame->stack);
	free(current_frame);
}
