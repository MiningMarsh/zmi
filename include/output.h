#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <stdarg.h>

#define printf print

void print(char* str, ...);
void initout();
void cleanout();

#endif
