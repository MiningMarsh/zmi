/*
 * dictionary.c
 *
 * Manipulates dictionaries.
 *
 *  Created on: 8-31, 2013
 *      Author: Joshua Songy
 */

#include <stdlib.h>
#include <stdbool.h>
#include "zint.h"
#include "memory.h"
#include "dictionary.h"

// Checks if a character is a seperator in the specified dictionary.
bool isSeperator(zaddress Dictionary, char Character) {
	// Newline is always a seperator.
	if(Character == '\n') {
		return true;
	}

	// First byte is the number of seperators.
	zbyte Number = getByte(Dictionary++);

	// The following n bytes are those seperators.
	for(zbyte I = 0; I < Number; ++I) {
		if(Character == getByte(Dictionary + I)) {
			return true;
		}
	}

	// No matching seperator has been found.
	return false;
}

zaddress dictionaryLookup(zaddress Dictionary, const char* String) {
	// Skip the seperators stored in the header.
	Dictionary += getByte(Dictionary) + 1;

	// Next is stored the length of each entry.
	zbyte Length = getByte(Dictionary);
	
	return 0;
}

char** tokenise(zaddress Dictionary, const char* String); 
