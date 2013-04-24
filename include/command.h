#ifndef COMMAND_H_
#define COMMAND_H_ 1

#include "zint.h"

// Hols the operands to opcodes.
uzword Operand[8];

// Execute the instruction pointed at by the PC and advance it to the next 
// available instruction.
void execNextInstruction();

// Initiate the Z-Machine VM opcode index, it's PC, and its memory.
void initZM();

#endif /* COMMAND_H_ */
