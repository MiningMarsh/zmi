/*
 * log.h
 *
 * The functions in this header are used to log machine execution and errors.
 *
 *  Created on: November 17, 2012
 *      Author: Joshua Songy
 */

#ifndef LOG_H_
#define LOG_H_ 1

#include <stdbool.h>
#include <stdarg.h>

// Types of messages available.
enum log_message_type {
	MWarning = 1,
	MNull = 0,
	MError = 2,
	MFatal = 3,
	MOk = 4
};

// Logs a message.
bool logMessage(const unsigned char Type, const char* const PrefixFormat, const char* const Format, ...);

// Opens a log.
bool logOpen(const char* const FileName);

// Closes a log.
void logClose();

// Tests if a log is currently open.
bool isLogOpen();

#endif /* LOG_H_ */
