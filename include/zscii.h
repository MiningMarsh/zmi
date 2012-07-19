#ifndef ZSCII_H
#define ZSCII_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


// Get raw z-characters from an address.
uint32_t* getzchar(uint16_t adr);

// Convert raw z-characters into a usable c style string.
char* tozscii(uint32_t* buffer);

#endif /* zscii.h */
