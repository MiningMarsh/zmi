#ifndef ROUTINE_H
#define ROUTINE_H

#include "zint.h"
#include <stdbool.h>

// Grab the branch data, compare it to the condition, and branch if they are both true.
void zBranch(bool condition);

// Grab the store target data and store this value in that variable.
void zStore(uzword value);

// Grab some zscii text from the PC stream and return it.
char* zGetStringFromPC();

#endif /* routine.h */
