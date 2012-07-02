#ifndef OBJECT_H
#define OBJECT_h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint16_t getpropadr(uint16_t obj, uint16_t prop);
uint16_t getobjflag(uint16_t obj, uint16_t flag);
void setparent(uint16_t obj, uint16_t val);
void setchild(uint16_t obj, uint16_t val);
void setsibling(uint16_t obj, uint16_t val);
void setobjflag(uint16_t obj, uint16_t flag, uint16_t val);
uint16_t getparent(uint16_t obj);
uint16_t getchild(uint16_t obj);
uint16_t getsibling(uint16_t obj);
uint16_t getproptableadr(uint16_t obj);

#endif
