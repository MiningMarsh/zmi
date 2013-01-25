#ifndef ZSCII_H
#define ZSCII_H 1

#include <stdint.h>

// Get raw z-characters from an address.
uint32_t* getZChars(uzword Address);

// Convert raw z-characters into a usable c style string.
char* zCharsToZSCII(uint32_t* Buffer);

#endif /* zscii.h */
