/*
 * log/Close.c
 *
 * Closes an open log.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "log.h"
#include "log/logFile.h"

void log_Close() {
	if(logFile) {
		fclose(logFile);
	}
}
