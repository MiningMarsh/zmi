/*
 * memory.h
 *
 * The functions in this header are used to manipulate Z-Machine memory.
 *
 *  Created on: November 17, 2012
 *      Author: Joshua Songy
 */

#ifndef MEMORY_H_
#define MEMORY_H_ 1

#include "zint.h"

// Holds the current routine state. Holds: PC, Stack, local variables,
// and return information for routine handling.
struct stackframe { // Holds the current routine state.
	struct stackframe* OldFrame;
	zaddress PC;
	uzword* Locals;
	uzword* Stack;
	uzbyte ReturnVar;
	uzbyte PassedArgs;
	uzword Depth;
}; typedef struct stackframe stackframe_t;

// The current Stack frame.
stackframe_t* CurrentZFrame;

// Load a story file into ram.
void loadRAM(const char* const FileName);

// Print a simple Stacktrace of the Stack frames.
void traceZStack();

// Expand a padded address.
zaddress expandPaddedAddress(const uzword PaddedAddress);

// Get a word from a ram address.
uzword getWord(const zaddress Address);

// Get a byte from a ram address.
uzbyte getByte(const zaddress Address);

// Set a word at a ram address.
void setWord(const zaddress Address, const uzword Value);

// Set a byte at a ram address.
void setByte(const zaddress Address, const uzbyte Value);

// Get a variable from a variable reference.
uzword getZVar(const uzbyte Variable);

// Set a variable reference to a value.
void setZVar(const uzbyte Variable, const uzword Value);

// Push a value to the local Stack.
void pushZStack(const uzword Value);

// Pop a value from the local Stack.
uzword popZStack();

// Get the current number of Stack frames.
uzword zFrameNumber();

// Pop a Stack frame (return).
void popZFrame();

// Push a Stack frame, and assign it some default values (call).
void pushZFrame();

// Get the Z-Machine revision number of the game file being run.
uzbyte getZRev();

// RAM of the Z-Machine.
uint8_t* RAM;

#endif /* MEMORY_H_ */
