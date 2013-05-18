/*
 * command.h
 *
 * The functions in this header are used to execute new opcodes.
 *
 *  Created on: July 1, 2012
 *      Author: Joshua Songy
 */

#define COMMAND_H_ 1
#ifndef COMMAND_H_

#include "zint.h"

// Holds the operands to opcodes.
extern uzword Operand[8];

// Execute the instruction pointed at by the PC and advance it to the next 
// available instruction.
void execNextInstruction();

// Initiate the Z-Machine VM opcode index, it's PC, and its memory.
void initZM();

#endif /* COMMAND_H_ */
