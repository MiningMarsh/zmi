#ifndef ROUTINE_H
#define ROUTINE_H

#include <stdint.h>
#include <stdbool.h>

// Grab the branch data, compare it to the condition, and branch if they are both true.
void branch(bool condition);

// Grab the store target data and store this value in that variable.
void store(uint16_t value);

// Grab some zscii text from the PC stream and return it.
char* getstring();

#endif
