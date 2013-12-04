/*
 * log/Message.h
 *
 * Logs a message. Exits program if a fatal message type is passed.
 *
 */

#ifndef LOG_MESSAGE_H_
#define LOG_MESSAGE_H_ 1

#include <stdbool.h>
#include <stdarg.h>
#include "log/logtype.h"

bool log_Message(
	int type, 
	const char* const prefix, 
	const char* const format, 
	...
);

#endif /* LOG_MESSAGE_H_ */
