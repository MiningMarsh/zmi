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

// Holds the terminal's width.
int TerminalWidth;
// Holds the terminal's height.
int TerminalHeight;

void initOutput() {
	// Default terminal size, if it can't be extracted.
	TerminalWidth = 80;
	TerminalHeight = 24;

	// OS specific terminal size extraction.
#	ifdef PLATFORM_LINUX
	struct winsize TerminalSize;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &TerminalSize);
	TerminalWidth = TerminalSize.ws_row;
	TerminalHeight = TerminalSize.ws_col;
#	endif
#	ifdef PLATFORM_WINDOWS
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleInfo);
	TerminalHeight = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left + 1;
	TerminalWidth = ConsoleInfo.srWindow.Bottom - ConsoleInfo.srWindow.Top + 1;
#	endif
}

void cleanOutput() {
}

void zPrint(char* String) {
	if(!String) {
		return;
	}
	printf("%s", String);
	/*static char* OutputBuffer = NULL;
	static char* OutputBufferSize = 0;
	static unsigned int CurrentPos = 0;
	
	if(OutputBuffer = NULL) {
		OutputBufferSize = strlen(String);
		OutputBuffer = malloc(sizeof(char)*OutputBufferSize);
		if(!OutputBuffer) {
			OutputBufferSize = 0;
			printf("%s", String);
			OutputBuffer = NULL;
			OutputBufferSize = 0;
			CurrentPos = 0;
			return;
		}
	} else {
		OutputBufferSize += strlen(String);
		char* NewOutputBuffer = realloc(OutputBuffer, OutputBufferSize);
		if(!NewOutputBuffer) {
			printf("%s", OutputBuffer);
			printf("%s\n", String);
			free(OutputBuffer);
			OutputBuffer = NULL;
			OutputBufferSize = 0;
			CurrentPos = 0;
			return;
		}
	}
	
	unsigned int CurrentWidth = 0;
	for(unsigned int Index = 0; Index < OutputBufferSize; Index++) {
		if(CurrentWidth + CurrentPos > TerminalWidth) {
			printf("\n");
			CurrentPos = 0;
		}
		switch(OutputBuffer[Index]) {
			case '\n':
				CurrentPos = 0;
				break;
			case ' '
		}
	}*/
}
