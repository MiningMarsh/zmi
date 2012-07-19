#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "memory.h"
#include "command.h"
#include "globalvars.h"

int main(int argc, char** argv) {
	char filefound = 0;
	char * filename;
	verbose_Debug = 0;
	strindir = 0;
	if(argc < 2) {
		printf("Usage: %s <filename> [OPTS]     (try --help)\n",argv[0]);
		exit(1);
	}
	for(int i = 0; i < argc; i++)
	{
		if(argv[i][0]=='-')
		{
			char * cmd = argv[i];
			if(!strcmp(cmd,"--help") || !strcmp(cmd,"-h"))
			{
				printf("Usage %s <filename> [OPTS]\n"
						"-h      --help                     Displays this dialogue\n"
						"-v [n]  --verbosity [n]            Displays intensive debugging\n"
						"-s      --show-string-indirection  shows string indirection\n"
						"\n"
						,argv[0]);
				exit(1);

			}else if(!strcmp(cmd,"-v") || !strcmp(cmd,"--verbosity"))
			{
				if(i == argc-1){
					printf("%s expects a value.\n",cmd);
					exit(1);
				}
				i++;
				verbose_Debug = argv[i][0]-'0';
				if(verbose_Debug > 8 || strlen(argv[i]) > 1){
					printf("%s expects a value 0-8\n",cmd);
					exit(1);
				}
			}else if(!strcmp(cmd,"-s") || !strcmp(cmd,"--show-string-indirection"))
			{
				strindir=1;
			}else
			{
				printf("%s is not a valid switch.\n",cmd);
				exit(0);
			}
		}else
		{
			if(i != 0)
			{
				filename = argv[i];
				filefound = 1;
			}
		}
	}
	if (!filefound)
	{
		printf("Usage: %s <filename> [OPTS]\n",argv[0]);
		exit(1);
	}
	printf("Using file %s.\n",filename);

	// Read the story file into ram.
	printf("MM's minimalistic Z-Machine interpreter.\n");
	printf("Revision 2 for platform PC and standard 1.0\n");
	loadRAM(filename);
	initZM();
	printf("%c[2J,%c[0;0H",27,27);
	fflush(stdout);
	while(1)
		execNextInstruction();
}

