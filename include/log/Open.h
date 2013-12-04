/*
 * log/Open.h
 *
 * Opens a log source. Fails if a log is already open. Returns false if 
 * it fails to open a new log.
 *
 */

#ifndef LOG_OPEN_H_
#define LOG_OPEN_H_ 1

#include <stdbool.h>

bool log_Open(
	const char* const filename
);

#endif /* LOG_H_ */