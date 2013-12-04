/*
 * log/Message.c
 *
 * Logs a message. Exits program if a fatal message type is passed.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "log.h"
#include "log/logFile.h"

// NULL means it failed.
static char* ExpandMessage(va_list args, va_list argsCopy, const char* const message) {
		
	if(!message) {
		return NULL;
	}

	// Find the size of the expanded prefix.
	int messageLength = vsnprintf(NULL, 0, message, args) + 1;
		
	// Check to see if the printf failed.
	if(messageLength < 0) {
		return NULL;
	}
		
	// Temporarily holds the expanded prefix, plus a null character.
	char newMessage[messageLength + 1];
		
	// Do the expannsion on the prefix.
	if(vsnprintf(newMessage, messageLength, message, argsCopy) < 0) {
		return NULL;
	}

	// Allocate space on the heap for the expanded prefix.
	char* messageBuffer = malloc(sizeof(char)*(strlen(newMessage) + 1));

	// Check to make sure we could allocate the space.
	if(!messageBuffer) {
		return NULL;
	}
			
	// Copy the string over.
	strcpy(messageBuffer, newMessage);

	// Return the expanded message.
	return messageBuffer;
}

bool log_Message(int type, const char* const prefix, const char* const message, ...) {
	// Maps message types to messages.
	char log_Messages[][30] = {
		"",
		"WARNING",
		"ERROR",
		"FATAL",
		"OK"
	};
	
	// Used to grab the extra formatting arguments.
	va_list args;
	// Start the argument grabbing after the format argument.
	va_start(args, message);
	// A copy of the arguments passed.
	va_list argsCopy;
	// Copy over the arguments.
	va_copy(argsCopy, args);
	
	// Holds the expanded prefix.
	char* expandedPrefix = NULL;

	// Expand the prefix if one exists.
	if(prefix) {
		// Holds the expanded message.
		expandedPrefix = ExpandMessage(args, argsCopy, prefix);

		// Only expand the prefix if it was passed.
		if(!expandedPrefix) {
			va_end(args);
			va_end(argsCopy);
			return false;
		}
	}
	
	// Expand the message in the same manner.
	char* expandedMessage = ExpandMessage(args, argsCopy, message);
	if(!expandedMessage) {
		free(expandedPrefix);
		va_end(args);
		va_end(argsCopy);
		return false;
	}

	// Return if no log is open.
	if(!logFile) {
		free(expandedPrefix);
		free(expandedMessage);
		return false;
	}

	int prefixLength = 0;

	// Prints the Message type, if it exists.
	if(strlen(log_Messages[(const unsigned int)type])) {
		fputs(log_Messages[(const unsigned int)type], logFile);
		fputs(": ", logFile);
	}

	// If a prefix was passed, print it and add its length to the pefix length.
	if(expandedPrefix != NULL) {
		if(strlen(expandedPrefix)) {
			prefixLength += strlen(expandedPrefix) + 2;
			fputs(expandedPrefix, logFile);
			fputs(": ", logFile);
		}
	}
	
	// Loop through the message and print it, doing special behavior on newlines.
	for(unsigned int i = 0; i < strlen(expandedMessage); i++) {
		
		// On newlines we need to advance a line and reprint the message prefix.
		if(expandedMessage[i] == '\n') {
			
			fputc('\n', logFile);
			// Prints the Message type, if it exists.
			if(strlen(log_Messages[(const unsigned int)type])) {
				fputs(log_Messages[(const unsigned int)type], logFile);
				fputs(": ", logFile);
			}
			
			// Print spaces equal to the message type.
			for(int i = 0; i != prefixLength; i++)
				fputc(' ', logFile);
		} else {
			// Otherwise just print the character.
			fputc(expandedMessage[i], logFile);
		}
	}

	// Output trailing newline.
	fputs("\n", logFile);
	// Flush the message.
	fflush(logFile);

	va_end(args);
	va_end(argsCopy);
	free(expandedPrefix);
	free(expandedMessage);
	return true;
}
