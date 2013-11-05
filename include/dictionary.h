/*
 * dictionary.h
 *
 * The functions in this header are used to read from the dictionary.
 *
 *  Created on: 8-31, 2013
 *      Author: Joshua Songy
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_ 1

#include <stdbool.h>
#include "zint.h"
#include "memory.h"

// Dictionary offset stored in 0x8 of the header.
inline zaddress dictionaryAddress() { getWord(0x8); }

bool isSeperator(zaddress Dictionary, char Character);

zaddress dictionaryLookup(zaddress Dictionary, const char* String);

char** tokenise(zaddress Dictionary, const char* String); 

#endif /* DICTIONARY_H_ */
