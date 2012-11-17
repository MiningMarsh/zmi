#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
FILE* Log = NULL;

char LogMessages[][30] = {
	"",
	"WARNING",
	"ERROR",
	"FATAL",
	"OK"
};

unsigned long MessageNumber = 0;

int LogMessage(const unsigned char Type, const char* const Prefix, const char* const Message) {
	if(!Log)
		return 0;
	int PrefixLength = 0;
	if(strlen(LogMessages[(const unsigned int)Type])) {
		fputs(LogMessages[(const unsigned int)Type], Log);
		fputs(": ", Log);
	}
	if(Prefix != NULL)
	if(strlen(Prefix)) {
		PrefixLength += strlen(Prefix) + 2;
		fputs(Prefix, Log);
		fputs(": ", Log);
	}
	for(int I = 0; I < strlen(Message); I++) {
		if(Message[I] == '\n') {
			fputc('\n', Log);
			if(strlen(LogMessages[(const unsigned int)Type])) {
				fputs(LogMessages[(const unsigned int)Type], Log);
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

int LogOpen(const char* const FileName) {
	if(Log) {
		fputs(LogMessages[MWarning],stderr);
		fputs("Log already open.\n",stderr);
		LogMessage(MWarning,"LogOpen()", "Message log already open.");
		return 0;
	}
	Log = fopen(FileName, "wba");
	if(!Log) {
		fputs(LogMessages[MWarning],stderr);
		fputs("Failed to open log file.\n",stderr);
		return 0;
	}
	LogMessage(MNull, "LogOpen()", "Log opened.");
	return 1;
}

void LogClose() {
	if(Log) {
		LogMessage(MNull, "LogClose()", "Log closed.");
		fclose(Log);
	}
}
