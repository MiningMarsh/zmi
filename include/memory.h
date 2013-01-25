#ifndef MEMORY_H
#define MEMORY_H 1

#include "zint.h"

// Holds the current routine state. Holds: PC, Stack, local variables,
// and return information for routine handling.
struct stackframe { // Holds the current routine state.
	struct stackframe* OldFrame;
	unsigned int PC;
	uzword* Locals;
	uzword* Stack;
	uzbyte ReturnVar;
	uzbyte PassedArgs;
}; typedef struct stackframe stackframe_t;

// The current Stack frame.
stackframe_t* CurrentZFrame;

// Load a story file into ram.
void loadRAM(char* file);

// Print a simple Stacktrace of the Stack frames.
void traceZStack();

// Expand a padded address.
uzword expandPaddedAddress(uzword PaddedAddress);

// Get a word from a ram address.
uzword getWord(unsigned int Address);

// Get a byte from a ram address.
uzbyte getByte(unsigned int Address);

// Set a word at a ram address.
void setWord(unsigned int Address, uzword Value);

// Set a byte at a ram address.
void setByte(unsigned int Address, uzbyte Value);

// Get a variable from a variable reference.
uzword getZVar(uzbyte Variable);

// Set a variable reference to a value.
void setZVar(uzbyte Variable, uzword Value);

// Push a value to the local Stack.
void pushZStack(uzword Value);

// Pop a value from the local Stack.
uzword popZStack();

// Get the current number of Stack frames.
uzword zFrameNumber();

// Pop a Stack frame (return).
void popZFrame();

// Push a Stack frame, and assign it some default values (call).
void pushZFrame();

uzbyte getZRev();

#endif /* memory.h */
