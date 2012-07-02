#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"
#include "command.h"

int main(int argc, char** argv) {
	if(argc < 2) {
		printf("No story file specified.\n");
		exit(1);
	}
	// Read the story file into ram.
	printf("MM's minimalistic Z-Machine interpreter.\n");
	printf("Revision 2 for platform PC and standard 1.0\n");
	for(int i = 0; i < 200;i++)
		printf("\n");
	loadRAM(argv[1]);
	initZM();
	fflush(stdout);
	while(1)
		execNextInstruction();
}

