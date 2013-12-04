/*
 * log/Open.c
 *
 * Opens a new log, fails if one is already open. Returns false on 
 * failure.
 * 
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
#include "log/logFile.h"

bool log_Open(const char* const filename) {
	// Check if a log is already open.
	if(logFile) {
		return false;
	}
	
	// A filename of stdout means to print to standard output.
	if(!strcmp(filename, "stdout")) {
		logFile = stdout;
		return true;
	}
	
	// A filename of stderr means to print to standard erroroutput.
	if(!strcmp(filename, "stderr")) {
		logFile = stderr;
		return true;
	}
	
	// Otherwise, we open a file of the name passed.
	logFile = fopen(filename, "wba");
	return logFile;
}
