#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

int logMessage(const unsigned char Type, const char* const Prefix, const char* const Message) {
	// Return if no log is open.
	if(!Log)
		return 0;

	// Holds the lngth of the mssage pefix.
	int PrefixLength = 0;

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

	for(unsigned int I = 0; I < strlen(Message); I++) {
		if(Message[I] == '\n') {
			fputc('\n', Log);
			// Prints the Message type, if it exists.
			if(strlen(logMessages[(const unsigned int)Type])) {
				fputs(logMessages[(const unsigned int)Type], Log);
				fputs(": ", Log);
			}
			for(int I = 0; I != PrefixLength; I++)
				fputc(' ', Log);
		} else {
			fputc(Message[I], Log);
		}
	}
	fputs("\n", Log);
	fflush(Log);
	return 1;
}

int logOpen(const char* const FileName) {
	// Print a warning if a log has already been opened.
	if(Log) {
		fputs(logMessages[MWarning],stderr);
		fputs("Log already open.\n",stderr);
		logMessage(MWarning,"LogOpen()", "Message log already open.");
		return 0;
	}
	if(!strcmp(FileName, "stdout")) {
		Log = stdout;
		logMessage(MNull, "LogOpen()", "Log opened.");
		return 1;
	}
	if(!strcmp(FileName, "stderr")) {
		Log = stderr;
		logMessage(MNull, "LogOpen()", "Log opened.");
		return 1;
	}
	// Open the log.
	Log = fopen(FileName, "wba");
	if(!Log) {
		fputs(logMessages[MWarning],stderr);
		fputs(": Failed to open log file.\n",stderr);
		return 0;
	}
	logMessage(MNull, "LogOpen()", "Log opened.");
	return 1;
}

void logClose() {
	// Close a log if one is open.
	if(Log) {
		if(Log != stderr) 
			logMessage(MNull, "LogClose()", "Log closed.");
		fclose(Log);
	}
}

bool isLogOpen() {
	return Log;
}
