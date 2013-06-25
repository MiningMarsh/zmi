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
unsigned int TerminalWidth;
// Holds the terminal's height.
unsigned int TerminalHeight;

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
	// Holds the current output being buffered.
	static char* OutputBuffer = NULL;
	// Holds the size of the buffer.
	static unsigned int OutputBufferSize = 0;
	// Holds the current line position on screen.
	static unsigned int CurrentPos = 0;
	
	// If no output buffer has been allocated yet, we need to allocate a new one.
	if(!OutputBuffer) {
		// The size of the buffer is going to be the same as the passed string.
		OutputBufferSize = strlen(String);
		// Allocate the buffer with an extra cell for null termination.
		OutputBuffer = malloc(sizeof(char)*OutputBufferSize + 1*sizeof(char));
		// If we failed, recover by just printing the string and resetting values.
		if(!OutputBuffer) {
			OutputBufferSize = 0;
			printf("%s", String);
			OutputBufferSize = 0;
			CurrentPos = 0;
			return;
		}
		// Null terminate the buffer.
		OutputBuffer[OutputBufferSize] = 0;
	} else {
		// The address to append the String to.	
		unsigned long long int CopyAddress = OutputBufferSize;
		// The buffer is going to be grown to accomadate string.
		OutputBufferSize += strlen(String);
		// Grow the buffer, including null terminating cell.
		char* NewOutputBuffer = realloc(OutputBuffer, (OutputBufferSize+1)*sizeof(char));
		// If we failed to allocate the buffer, recover.
		if(!NewOutputBuffer) {
			printf("%s", OutputBuffer);
			printf("%s", String);
			free(OutputBuffer);
			OutputBuffer = NULL;
			OutputBufferSize = 0;
			CurrentPos = 0;
			return;
		}
		OutputBuffer = NewOutputBuffer;
		strcpy(OutputBuffer + CopyAddress, String);
	}
	
	for(unsigned int Index = 0; Index < OutputBufferSize; Index++) {
		if(Index + CurrentPos > TerminalWidth) {
			printf("\n");
			CurrentPos = 0;
		}
		switch(OutputBuffer[Index]) {
			case '\r':
				CurrentPos = 0;
			case ' ':
			case '\n': {
				int Newline = 0;
				if(OutputBuffer[Index] == '\n') {
					Newline = 1;
				}
				OutputBuffer[Index] = 0;
				char* NewOutputBuffer = malloc((OutputBufferSize - (Index+1))*sizeof(char));
				if(!NewOutputBuffer) {
					printf("%s\n", OutputBuffer);
					free(OutputBuffer);
					OutputBuffer = NULL;
					OutputBufferSize = 0;
					CurrentPos = 0;
					return;
				}
				OutputBufferSize -= Index+1;
				strcpy(NewOutputBuffer, OutputBuffer+Index+1);
				OutputBuffer[Index] = 0;
				printf("%s", OutputBuffer);
				if(!Newline)
					putchar(' ');
				free(OutputBuffer);
				OutputBuffer = NewOutputBuffer;
				CurrentPos = 0;
				if(Newline) {
					putchar('\n');
				}
				break; }
		}
	}
}
