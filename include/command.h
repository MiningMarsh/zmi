#ifndef COMMAND_H
#define COMMAND_H 1

#include "zint.h"

// The operands to the operation.
uzword Operand[8];

// Execute the instruction pointed at by the PC and advance it to the next available instruction.
void execNextInstruction();

// Initiate the machine operation index, it's PC, and memory.
void initZM();

#endif /* memory.h */
