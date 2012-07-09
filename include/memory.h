#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#ifndef Z_REV
# define Z_REV getbyte(0)
#endif
struct stack_frame { // Holds the current routine state.
	struct stack_frame* old_frame;
	uint32_t PC;
	uint16_t* locals;
	uint16_t* stack;
	uint8_t retvar;
	uint8_t nargs;
};

struct stack_frame* current_frame;

void loadRAM(char* file);
void stacktrace();
uint32_t exPAdr(uint16_t padr);
uint16_t getword(int adr);
uint8_t getbyte(int adr);
void setword(int adr, int16_t value);
void setbyte(int adr, int8_t value);
uint16_t getvar(uint8_t var);
void setvar(uint8_t var, uint16_t val);
void push(uint16_t val);
uint16_t pop();
uint16_t framenum();
void popframe();
void pushframe();
#endif /* memory.h */
