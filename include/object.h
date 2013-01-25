#ifndef OBJECT_H
#define OBJECT_H 1

#include <stdbool.h>
#include "zint.h"

// Get the address of a property on an object. This function does not check to see if the object is 0.
uzword getPropertyAddress(uzword Object, uzword Property);

// Get a flag off an object, if it is valid.
bool getObjectFlag(uzword Object, uzword Flag);

// Set the parent of an object.
void setParent(uzword Object, uzword val);

// Set the child of an object.
void setChild(uzword Object, uzword Value);

// Set the sibling of an object.
void setSibling(uzword Object, uzword Value);

// Set a flag of an object to either on or off.
void setObjectFlagValue(uzword Object, uzword Flag, bool Value);

// Get the parent of an object.
uzword getParent(uzword Object);

// Get the child of an object.
uzword getChild(uzword Object);

// Get the sibling of an object.
uzword getSibling(uzword Object);

// Get the property table address of an object. This is a bit useless outside of the other object functions.
uzword getPropertyTableAddress(uzword Object);

#endif /* object.h */
