#ifndef ROUTINE_H
#define ROUTINE_H

#include <stdint.h>
#include <stdbool.h>

void branch(bool condition);
void store(uint16_t value);
char* getstring();

#endif
