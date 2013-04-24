#ifndef LOG_H_
#define LOG_H_ 1

#include <stdbool.h>

enum log_message_type {
	MWarning = 1,
	MNull = 0,
	MError = 2,
	MFatal = 3,
	MOk = 4
};

int logMessage(const unsigned char Type, const char* const Prefix, const char* const Message);

int logOpen(const char* const FileName);

void logClose();

bool isLogOpen();

#endif /* LOG_H_ */
