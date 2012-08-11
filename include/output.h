#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <stdarg.h>

// Printf for the Z-Machine.
void zPrint(char* str, ...);

// Initiate output modes for the terminal and Z-Machine.
void initOutput();

// Revert terminal output modes.
void cleanOutput();

#endif /* output.h */
