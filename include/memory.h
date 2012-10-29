// Allow getZRev() to get the current story file z-code revision.

#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>


// Holds the current routine state. Holds: PC, Stack, local variables,
// and return information for routine handling.
struct stackframe { // Holds the current routine state.
	struct stackframe* OldFrame;
	uint32_t PC;
	uint16_t* Locals;
	uint16_t* Stack;
	uint8_t ReturnVar;
	uint8_t PassedArgs;
}; typedef struct stackframe stackframe_t;

// The current Stack frame.
stackframe_t* CurrentZFrame;

// Load a story file into ram.
void loadRAM(char* file);

// Print a simple Stacktrace of the Stack frames.
void traceZStack();

// Expand a padded address.
uint32_t exPadAdr(uint16_t padr);

// Get a word from a ram address.
uint16_t getWord(unsigned int Address);

// Get a byte from a ram address.
uint8_t getByte(unsigned int Address);

// Set a word at a ram address.
void setWord(unsigned int Address, int Value);

// Set a byte at a ram address.
void setByte(unsigned int Address, int Value);

// Get a variable from a variable reference.
uint16_t getZVar(uint8_t var);

// Set a variable reference to a value.
void setZVar(uint8_t var, uint16_t val);

// Push a value to the local Stack.
void pushZStack(uint16_t val);

// Pop a value from the local Stack.
uint16_t popZStack();

// Get the current number of Stack frames.
uint16_t zFrameNumber();

// Pop a Stack frame (return).
void popZFrame();

// Push a Stack frame, and assign it some default values (call).
void pushZFrame();

uint8_t getZRev();

#endif /* memory.h */
