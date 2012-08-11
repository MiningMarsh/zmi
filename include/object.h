#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Get the address of a property on an object. This function does not check to see if the object is 0.
uint16_t getPropertyAdr(uint16_t obj, uint16_t prop);

// Get a flag off an object, if it is valid.
uint16_t getObjectFlag(uint16_t obj, uint16_t flag);

// Set the parent of an object.
void setParent(uint16_t obj, uint16_t val);

// Set the child of an object.
void setChild(uint16_t obj, uint16_t val);

// Set the sibling of an object.
void setSibling(uint16_t obj, uint16_t val);

// Set a flag of an object to either on or off.
void setObjectFlagValue(uint16_t obj, uint16_t flag, uint16_t val);

// Get the parent of an object.
uint16_t getParent(uint16_t obj);

// Get the child of an object.
uint16_t getChild(uint16_t obj);

// Get the sibling of an object.
uint16_t getSibling(uint16_t obj);

// Get the property table address of an object. This is a bit useless outside of the other object functions.
uint16_t getPropertyTableAdr(uint16_t obj);

#endif /* object.h */
