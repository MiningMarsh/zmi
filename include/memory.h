#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Allow Z_REV to get the current story file z-code revision.
#define Z_REV getbyte(0)

// Holds the current routine state. Holds: PC, stack, local variables,
// and return information for routine handling.
struct stack_frame {
	struct stack_frame* old_frame;
	uint32_t PC;
	uint16_t* locals;
	uint16_t* stack;
	uint8_t retvar;
	uint8_t nargs;
};

// The current stack frame.
struct stack_frame* current_frame;

// Load a story file into ram.
void loadRAM(char* file);

// Print a simple stacktrace of the stack frames.
void stacktrace();

// Expand a padded address.
uint32_t exPAdr(uint16_t padr);

// Get a word from a ram address.
uint16_t getword(int adr);

// Get a byte from a ram address.
uint8_t getbyte(int adr);

// Set a word at a ram address.
void setword(int adr, int16_t value);

// Set a byte at a ram address.
void setbyte(int adr, int8_t value);

// Get a variable from a variable reference.
uint16_t getvar(uint8_t var);

// Set a variable reference to a value.
void setvar(uint8_t var, uint16_t val);

// Push a value to the local stack.
void push(uint16_t val);

// Pop a value from the local stack.
uint16_t pop();

// Get the current number of stack frames.
uint16_t framenum();

// Pop a stack frame (return).
void popframe();

// Push a stack frame, and assign it some default values (call).
void pushframe();

#endif /* memory.h */
