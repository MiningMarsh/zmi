#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <stdarg.h>

// Printf for the Z-Machine.
void print(char* str, ...);

// Initiate output modes for the terminal and Z-Machine.
void initout();

// Revert terminal output modes.
void cleanout();

#endif /* output.h */
