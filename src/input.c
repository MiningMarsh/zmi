#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include "memory.h"
#include "command.h"

static struct termios term_settings;

void initin() {
	tcgetattr(STDIN_FILENO,&term_settings);
	struct termios term = term_settings;
	term.c_lflag &= ~(ICANON|ECHO);
	term.c_cc[VTIME] = 1;
	term.c_cc[VMIN] = 0;
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&term);
}
void cleanin() {
	tcsetattr(STDIN_FILENO,TCSANOW,&term_settings);
}
void printstat() {
}
char readchar(){
	return 0;
}

void readstr() {
	unsigned int maxsz = getbyte(operand[0]);
	if(Z_REV < 5)
		maxsz--;
	printf("maxsz is %u\n",maxsz);
	char* line = NULL;
	line = calloc(sizeof(char), maxsz+ 2);
	int loop = 1;
	int pos = 0;
	int strptr=0;
	while(loop) {
		char c = 0;
		int i = read(STDIN_FILENO,&c,1);
		if (c==0x1b){
			read(STDIN_FILENO,&c,1);
			if (c=='['){
				read(STDIN_FILENO,&c,1);
				switch(c){
					case 'A':
						//up
						break;
					case 'B':
						//down
						break;
					case 'C':
						if(strptr < maxsz-1){
							printf("\x1b[C");
							strptr++;
						}
						break;
					case 'D':
						if(strptr > 0){
							printf("\x1b[D");
							strptr--;
						}
						break;
				}
			}
			c = 0;
		}
		if(c == 10){
			loop = 0;
			c = 0;
		}
		if(c == 127){
			if(strptr>0){
				c = 126;
				strptr--;
				printf("\x1b[D");
			}else{
			c=0;
			}
		}
		if(c == 126){
			int x;
			for(x = strptr; x < maxsz-1; x++){
				line[x] = line[x+1];
				char v = line[x];
				if(v==0)
					v = 32;
				printf("\x1b[C\x08%c",v);
			}
			line[maxsz-1]=0;
			printf("\x1b[C\x08 ");
			for(x = strptr; x < maxsz; x++){
				printf("\x1b[D");
			}
			c=0;
		}
		if(c != 0){
			if(line[maxsz-1] == 0){
				int x;
				for(x = maxsz -1; x > strptr; x--){
					line[x] = line[x-1];
					printf("\x1b[C");
				}
				printf("\x1b[C");
				for(x = maxsz-1; x >strptr; x--){
					char v = line[x];
					if(v==0)
						v=32;
					printf("\x08%c\x1b[D",v);
				}
				line[strptr] = c;
				printf("\x08%c",c);
				strptr++;
			}
		}
		if(i == 0) {
		}
		fflush(stdout);
	}
	int i;
	int mxpos=0;
	for(i = 0; i < maxsz; i++){
		if(line[i] != 0)
			mxpos = i;
		else
			line[i]=32;
	}
	line[mxpos+1] = 0;
	line[mxpos+2] = 0;
	printf("\n%s\n",line);
}