/*
 * log/IsOpen.c
 *
 * Returns true if a log is open.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "log.h"
#include "log/logFile.h"

bool log_IsOpen() {
	return logFile;
}
