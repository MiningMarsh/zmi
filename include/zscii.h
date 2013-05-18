/*
 * zscii.h
 *
 * The functions in this header are used to convert zstrings to c strings.
 *
 *  Created on: July 1, 2012
 *      Author: Joshua Songy
 */

#ifndef ZSCII_H_
#define ZSCII_H_ 1

#include <stdint.h>

// Get raw z-characters from an address.
uint32_t* getZChars(uzword Address);

// Convert raw z-characters into a usable c style string.
char* zCharsToZSCII(uint32_t* Buffer);

#endif /* ZSCII_H_ */
