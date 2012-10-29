// Allow getZRev() to get the current story file z-code revision.

#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>


// Holds the current routine state. Holds: PC, stack, local variables,
// and return information for routine handling.
struct stackframe { // Holds the current routine state.
	struct stack_frame* OldFrame;
	uint32_t PC;
	uint16_t* Locals;
	uint16_t* Stack;
	uint8_t ReturnVar;
	uint8_t PassedArgs;
}; typedef struct stackframe stackframe_t;

// The current stack frame.
stackframe_t* CurrentZFrame;

// Load a story file into ram.
void loadRAM(char* file);

// Print a simple stacktrace of the stack frames.
void traceZStack();

// Expand a padded address.
uint32_t exPadAdr(uint16_t padr);

// Get a word from a ram address.
uint16_t getWord(int adr);

// Get a byte from a ram address.
uint8_t getByte(int adr);

// Set a word at a ram address.
void setWord(int adr, int16_t value);

// Set a byte at a ram address.
void setByte(int adr, int8_t value);

// Get a variable from a variable reference.
uint16_t getZVar(uint8_t var);

// Set a variable reference to a value.
void setZVar(uint8_t var, uint16_t val);

// Push a value to the local stack.
void pushZStack(uint16_t val);

// Pop a value from the local stack.
uint16_t popZStack();

// Get the current number of stack frames.
uint16_t zFrameNumber();

// Pop a stack frame (return).
void popZFrame();

// Push a stack frame, and assign it some default values (call).
void pushZFrame();

uint8_t getZRev();

#endif /* memory.h */
