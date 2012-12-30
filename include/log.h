#ifndef LOG_H
#define LOG_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum log_message_type {
	MWarning = 1,
	MNull = 0,
	MError = 2,
	MFatal = 3,
	MOk = 4
};

int logMessage(const unsigned char Type, const char* const Prefix, const char* const Message);

int LogOpen(const char* const FileName);

void LogClose();

#endif
