#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Get the address of a property on an object. This function does not check to see if the object is 0.
uint16_t getpropadr(uint16_t obj, uint16_t prop);

// Get a flag off an object, if it is valid.
uint16_t getobjflag(uint16_t obj, uint16_t flag);

// Set the parent of an object.
void setparent(uint16_t obj, uint16_t val);

// Set the child of an object.
void setchild(uint16_t obj, uint16_t val);

// Set the sibling of an object.
void setsibling(uint16_t obj, uint16_t val);

// Set a flag of an object to either on or off.
void setobjflag(uint16_t obj, uint16_t flag, uint16_t val);

// Get the parent of an object.
uint16_t getparent(uint16_t obj);

// Get the child of an object.
uint16_t getchild(uint16_t obj);

// Get the sibling of an object.
uint16_t getsibling(uint16_t obj);

// Get the property table address of an object. This is a bit useless outside of hte other object functions.
uint16_t getproptableadr(uint16_t obj);

#endif /* object.h */
