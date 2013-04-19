#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "memory.h"
#include "input.h"
#include "platform.h"

#ifdef PLATFORM_LINUX
#	include <termios.h>
#	include <sys/ioctl.h>
#endif

#ifdef PLATFORM_WINDOWS
#	include <windows.h>
#endif

#ifdef PLATFORM_LINUX
// Used to hold what the terminal settings were before this program started.
static struct termios TerminalSettings;
#endif

// Holds the terminals width and height.
int TerminalWidth, TerminalHeight;

void initInput() {
	// Default terminal size if it can't be extracted.
	TerminalWidth = 80;
	TerminalHeight = 24;

	// OS specific terminal size extraction.
#	ifdef PLATFORM_LINUX
	struct winsize TerminalSize;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &TerminalSize);
	TerminalWidth = TerminalSize.ws_col;
	TerminalHeight = TerminalSize.ws_col;
#	endif

#	ifdef PLATFORM_LINUX
	// Save current terminal state in TerminalSettings.
	tcgetattr(STDIN_FILENO,&TerminalSettings);

	// Turn the terminal into non-canonical mode.
	struct termios NewTerminalSettings = TerminalSettings;
	NewTerminalSettings.c_lflag &= ~(ICANON|ECHO);
	NewTerminalSettings.c_cc[VTIME] = 1;
	NewTerminalSettings.c_cc[VMIN] = 0;
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&NewTerminalSettings);
#	endif

}

void cleanInput() {
#	ifdef PLATFORM_LINUX
	// Restore the terminal state.
	tcsetattr(STDIN_FILENO,TCSANOW,&TerminalSettings);
#	endif
}

// Read a character in from the terminal.
char readChar() {
	return 0;
}

// The Z-Machine prompt reading.
void readString() {
	// THIS IS A TEMPORARY EXIT POINT FOR USE WITH VALGRIND.
	exit(0);
	/* unsigned int maxsz = getByte(Operand[0]);
	maxsz = maxsz>TerminalWidth? TerminalWidth:maxsz;
	maxsz = maxsz<20? 20:maxsz;
	maxsz--;
	if(getZRev() < 5)
		maxsz--;
	if(g_VerboseDebug >=4)
		printf("maxsz is %u\n",maxsz);
	char* line = NULL;
	line = calloc(sizeof(char), maxsz+ 2);
	int loop = 1;
	int strptr=0;
	while(loop) {
		char c = 0;
		int i =read(STDIN_FILENO,&c,1);
		if (c==0x1b) {
			int i =read(STDIN_FILENO,&c,1);
			if(i) {};
			if (c=='[') {
				int i = read(STDIN_FILENO,&c,1);
				if(i) {};
				switch(c) {
					case 'A':
						//up
						break;
					case 'B':
						//down
						break;
					case 'C':
						//right
						if(strptr < maxsz-1) {
							printf("\x1b[C");
							strptr++;
						}
						break;
					case 'D':
						//left
						if(strptr > 0) {
							printf("\x1b[D");
							strptr--;
						}
						break;
				}
			}
			c = 0;
		}
		if(c == 10) {
			loop = 0;
			c = 0;
		}
		if(c == 127) {
			if(strptr>0) {
				c = 126;
				strptr--;
				printf("\x1b[D");
			} else {
				c=0;
			}
		}
		if(c == 126) {
			int x;
			for(x = strptr; x < maxsz-1; x++) {
				line[x] = line[x+1];
				char v = line[x];
				if(v==0)
					v = 32;
				printf("\x1b[C\x08%c",v);
			}
			line[maxsz-1]=0;
			printf("\x1b[C\x08 ");
			for(x = strptr; x < maxsz; x++) {
				printf("\x1b[D");
			}
			c=0;
		}
		if(c != 0) {
			if(line[maxsz-1] == 0) {
				int x;
				for(x = maxsz -1; x > strptr; x--) {
					line[x] = line[x-1];
					printf("\x1b[C");
				}
				printf("\x1b[C");
				for(x = maxsz-1; x >strptr; x--) {
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
		fflush(stdout);
	}
	int i;
	int mxpos=0;
	for(i = 0; i < maxsz; i++) {
		if(line[i] != 0)
			mxpos = i;
		else
			line[i]=32;
	}
	line[mxpos+1] = 0;
	line[mxpos+2] = 0;
	printf("\n");
	//THE FOLLOWING FREE IS TEMPORARY
	free(line);
	*/
}
