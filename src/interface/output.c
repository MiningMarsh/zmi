#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "memory.h"
#include "command.h"
#include "platform.h"

#ifdef PLATFORM_LINUX
#	include <termios.h>
#	include <sys/ioctl.h>
#endif

#ifdef PLATFORM_WINDOWS
#	include <windows.h>
#endif

// Holds the terminals width and height.
int TerminalWidth, TerminalHeight;

void initOutput() {
	// Default terminal size, if it can't be extracted.
	TerminalWidth = 80;
	TerminalHeight = 24;

	// OS specific terminal size extraction.
#	ifdef PLATFORM_LINUX
	struct winsize TerminalSize;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &TerminalSize);
	TerminalWidth = TerminalSize.ws_col;
	TerminalHeight = TerminalSize.ws_col;
#	endif
}

void cleanOutput() {
}

void zPrint(char* String, ...) {
	// Used to access the variable arguments.
	va_list Arguments;
	va_start(Arguments, String);
	if(!TerminalWidth)
		TerminalWidth=20;
	// Holds the cursor position, used for word wrapping.
	int Position = 0;
	// ditto.
	int StringSize = 0;
	// Holds the next word to be printed.
	char Word[1024];
	// Holds the size of the last word printed.
	int WordSize = 0;

	// Parse special characters.
	while(String[StringSize]) {
		switch(String[StringSize]) {

			// Used im the same style as printf.
			case '%': {
				StringSize++;
				switch(String[StringSize]) {
					case 's': {
						char *ArgString;
						ArgString = va_arg(Arguments,char*);
						int Position = 0;
						while(ArgString[Position]) {
							Word[WordSize] = ArgString[Position];
							Position++;
							WordSize++;
						}
						break; }
					case 'i': {

					}
					default:
						printf("Invalid expansion passed to print.\n");
				}
			break; }
			case '\n':
			case '\r':
				Word[WordSize] = 0;
				printf("%s\n",Word);
				WordSize = 0;
				Position = 0;
				break;
			case '\b':
				Position--;
				putchar('\b');
				break;
			case ' ':
				if(Position + WordSize > TerminalWidth) {
					Position = 0;
					putchar('\n');
				}
				Word[WordSize] = 0;
				printf("%s",Word);
				if(WordSize + Position != TerminalWidth)
					putchar(' ');
				Position += WordSize + 1;
				WordSize = 0;
				break;
			default:
				Word[WordSize] = String[StringSize];
				WordSize++;
				break;
		}
		StringSize++;
	}
	if(WordSize) {
	if(Position + WordSize > TerminalWidth) {
		Position = 0;
		putchar('\n');
	}
	Word[WordSize]=0;
	printf("%s",Word);
	WordSize--;
	Position += WordSize;
	}
	va_end(Arguments);
}
