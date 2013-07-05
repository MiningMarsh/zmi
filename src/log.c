#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "log.h"

FILE* Log = NULL;

// This array holds the string version of the enum values.
char logMessages[][30] = {
	"",
	"WARNING",
	"ERROR",
	"FATAL",
	"OK"
};

// Log a message into the current log file/stream. If none is open, the message is thrown away.
bool logMessage(const unsigned char Type, const char* const PrefixFormat, const char* const Format, ...) {

	assert(Format);

	va_list Args;
	va_start(Args, Format);
	va_list ArgsCopy;
	va_copy(ArgsCopy, Args);
	
	char* Prefix = NULL;
	int PrefixLength;
	
	if(PrefixFormat) {
		PrefixLength = vsnprintf(NULL, 0, PrefixFormat, Args);
		char NewPrefix[PrefixLength + 2];
		vsnprintf(NewPrefix, PrefixLength + 1, PrefixFormat, ArgsCopy);
		
		Prefix = malloc(sizeof(char)*(strlen(NewPrefix) + 1));
		if(Prefix)
			strcpy(Prefix, NewPrefix);
	}
	
	unsigned int MessageLength = vsnprintf(NULL, 0, Format, Args);
	char Message[MessageLength + 2];
	vsnprintf(Message, MessageLength + 1, Format, ArgsCopy);
	
	va_end(Args);
	va_end(ArgsCopy);

	vsnprintf(NULL, 0, Format, Args);
	// Return if no log is open.
	if(!Log) {
		free(Prefix);
		return false;
	}

	PrefixLength = 0;

	// Prints the Message type, if it exists.
	if(strlen(logMessages[(const unsigned int)Type])) {
		fputs(logMessages[(const unsigned int)Type], Log);
		fputs(": ", Log);
	}

	// If a prefix was passed, print it and add its length to the pefix length.
	if(Prefix != NULL)
	if(strlen(Prefix)) {
		PrefixLength += strlen(Prefix) + 2;
		fputs(Prefix, Log);
		fputs(": ", Log);
	}
	
	// Loop through the message and print it, doing special behavior on newlines.
	for(unsigned int I = 0; I < strlen(Message); I++) {
		// On newlines we need to advance a line and reprint the message prefix.
		if(Message[I] == '\n') {
			fputc('\n', Log);
			// Prints the Message type, if it exists.
			if(strlen(logMessages[(const unsigned int)Type])) {
				fputs(logMessages[(const unsigned int)Type], Log);
				fputs(": ", Log);
			}
			// Print spaces equal to the message type.
			for(int I = 0; I != PrefixLength; I++)
				fputc(' ', Log);
		} else {
			// Otherwise just print the character.
			fputc(Message[I], Log);
		}
	}
	// Output trailing newline.
	fputs("\n", Log);
	// Flush the message.
	fflush(Log);
	free(Prefix);
	return true;
}

bool logOpen(const char* const FileName) {
	// Print a warning if a log has already been opened.
	if(Log) {
		fputs(logMessages[MWarning],stderr);
		fputs("Log already open.\n",stderr);
		logMessage(MWarning,"LogOpen()", "Message log already open.");
		return false;
	}
	
	// A filename of stdout means to print to standard output.
	if(!strcmp(FileName, "stdout")) {
		Log = stdout;
		logMessage(MNull, "LogOpen()", "Log opened.");
		return true;
	}
	
	// A filename of stderr means to print to standard erroroutput.
	if(!strcmp(FileName, "stderr")) {
		Log = stderr;
		logMessage(MNull, "LogOpen()", "Log opened.");
		return true;
	}
	
	// Otherwise, we open a file of the name passed.
	Log = fopen(FileName, "wba");
	if(!Log) {
		fputs(logMessages[MWarning],stderr);
		fputs(": Failed to open log file.\n",stderr);
		return false;
	}
	logMessage(MNull, "LogOpen()", "Log opened.");
	return true;
}

void logClose() {
	// Close a log if one is open.
	if(Log) {
		if(Log != stderr) 
			logMessage(MNull, "LogClose()", "Log closed.");
		fclose(Log);
	}
}

// Return true if a log is open, false otherwise.
bool isLogOpen() {
	return Log;
}
