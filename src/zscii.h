#ifndef ZSCII_H
#define ZSCII_h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t* getzchar(uint16_t adr);
char* tozscii(uint32_t* buffer);

#endif
