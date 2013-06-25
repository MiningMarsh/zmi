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
	TerminalHeight = TerminalSize.ws_row;
	TerminalWidth = TerminalSize.ws_col;
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
	static int OutputBufferSize = 0;
	// Holds the current line position on screen.
	static int CurrentPos = 0;
	
	// NULL string means to flush output.
	if(!String) {
		printf("%s", OutputBuffer);
		CurrentPos += strlen(OutputBuffer);
		free(OutputBuffer);
		OutputBuffer = NULL;
		OutputBufferSize = 0;
		return;
	}

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
			CurrentPos += OutputBufferSize;
			OutputBufferSize = 0;
			return;
		}
		strcpy(OutputBuffer, String);
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
			CurrentPos += OutputBufferSize;
			OutputBufferSize = 0;
			return;
		}
		// Reassign to the new pointer if we successfully re-allocated the buffer.
		OutputBuffer = NewOutputBuffer;
		// Copy the new string onto the buffer.
		strcpy(OutputBuffer + CopyAddress, String);
	}
	
	for(int Index = 0; Index < OutputBufferSize; Index++) {
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
					printf("%s", OutputBuffer);
					free(OutputBuffer);
					OutputBuffer = NULL;
					CurrentPos += OutputBufferSize;
					OutputBufferSize = 0;
					return;
				}
				OutputBufferSize -= Index+1;
				strcpy(NewOutputBuffer, OutputBuffer+Index+1);
				OutputBuffer[Index] = 0;
				if(CurrentPos + Index >= TerminalWidth-5)
				for(int i = Index; i > 0 ; i--)
				{
					if(OutputBuffer[i] == ' ')
					{
						OutputBuffer[i] = '\n';
						CurrentPos = Index-i;
						break;
					}
				}
				printf("%s", OutputBuffer);
				if(!Newline)
					putchar(' ');
				free(OutputBuffer);
				OutputBuffer = NewOutputBuffer;
				CurrentPos += Index;
				if(Newline) {
					putchar('\n');
					CurrentPos = 0;
				}
				break; }
		}
	}
}
