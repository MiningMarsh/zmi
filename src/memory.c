#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

uint8_t* RAM = NULL; // Holds the file.
// Globals and locals are ptrs so that they can easil be stored on the
// stack.
struct stack_frame { // Holds the current routine state.
	struct stack_frame* old_frame;
	uint32_t PC;
	uint16_t* locals;
	uint16_t* stack;
	uint8_t retvar;
	uint8_t nargs;
};

struct stack_frame* current_frame;
int size;

void loadRAM(char* file) {
	if(RAM != NULL) {
		free(RAM);
		RAM = NULL;
	}
	FILE* storyfile;
	storyfile = fopen(file, "rb");
	if(storyfile == NULL) {
		fputs("Error opening story file.\n",stderr);
		exit (1);
	}
	fseek(storyfile, 0, SEEK_END);
	int size = ftell(storyfile);
	rewind(storyfile);
	RAM = (int8_t*)malloc(sizeof(int8_t)*size);
	if(RAM == NULL) {
		fputs("Error allocating ram.\n",stderr);
		exit (1);
	}
	for(int i = 0; i < size; i++) {
		char buf[1];
		if(fread(buf, 1, 1, storyfile)!= 1) {
			fputs("Error reading story file.\n",stderr);
			exit(1);
		}
		RAM[i] = (uint8_t)buf[0];
	}
	size /= 1024;
	int maxsize;
	switch(RAM[0]) {
		case 1:
		case 2:
		case 3:
			maxsize = 128;
			break;
		case 4:
		case 5:
			maxsize = 256;
			break;
		case 7:
			maxsize = 320;
			break;
		case 6:
		case 8:
			maxsize = 512;
			break;
	}
	if(size > maxsize) {
		fputs("Story file too large.\n", stderr);
		exit (1);
	}
	fclose(storyfile);
}

// Get the word beggining at ram address adr.
uint16_t getword(int adr) {
	return RAM[adr+1]|(RAM[adr]<<8);
}

// Get the byte beggining at ram address adr.
uint8_t getbyte(int adr) {
	return RAM[adr];
}

// Set the word beggining at ram address adr to value.
void setword(int adr, int16_t value) {
	if(adr == 0) {
		fputs("Tried to set Z_REV.\n",stderr);
		exit(1);
	}
	RAM[adr+1] = value&0xFF;
	RAM[adr] = (value>>8)&0xFF;
}

// Set the byte beggining at ram address adr to value.
void setbyte(int adr, int8_t value) {
	if(adr == 0) {
		fputs("Tried to set Z_REV.\n",stderr);
		exit(1);
	}
	RAM[adr] = value&0xFF;
}

// Return the expanded packed adress depending on the machine.
uint32_t exPAdr(uint16_t padr) {
	unsigned int machine = getbyte(0);
	if(machine <= 3)
		return 2*padr;
	if(machine <=7)
		return 4*padr;
	return 8*padr;
}

// Pop from the stack.
uint16_t pop() {
	if(current_frame->stack == NULL || current_frame->stack[0] < 1) {
		fputs("Tried POPing empty stack.\n", stderr);
		exit(1);
	}
	current_frame->stack[0]--;
	return current_frame->stack[current_frame->stack[0] + 1];
}
// Push to the stack.
void push(uint16_t val) {
	if(current_frame->stack == NULL) {
		current_frame->stack = malloc(sizeof(uint16_t)*1024);
		current_frame->stack[0] = 0;
	}
	current_frame->stack[0]++;
	if(current_frame->stack == NULL) {
		fputs("Error PUSHing stack.\n", stderr);
		exit(1);
	}
	current_frame->stack[current_frame->stack[0]] = val;
}
// Get the value of variable reference var.
uint16_t getvar(uint8_t var) {
	if(var > 15)
		return getword(getword(0x06*2) + 2*(var - 16));
	return var > 0 ? current_frame->locals[var] : pop();
}
void setvar(uint8_t var, uint16_t val) {
	if(var > 15)
		setword(getword(0x06*2) + 2*(var - 16), val);
	else if(var == 0)
		push(val);
	else
		current_frame->locals[var] = val;
}

// Push a copy of the current routinte (stack frame).
void pushframe() {
	struct stack_frame* new_frame = malloc(sizeof(struct stack_frame));
	if(new_frame == NULL) {
		fputs("Not enough memory to PUSH a stack frame.\n",stderr);
		exit(1);
	}
	new_frame->old_frame = current_frame;
	current_frame = new_frame;
	current_frame->locals = NULL;
	current_frame->stack = NULL;
	current_frame->retvar = 1;
}
// Pop a stack frame.
void popframe() {
	if(current_frame->old_frame == NULL) {
		fputs("Attempted to POP main stack frame.\n", stderr);
		exit(1);
	}
	free(current_frame->locals);
	free(current_frame->stack);
	struct stack_frame* dead_frame = current_frame;
	current_frame = dead_frame->old_frame;
	free(dead_frame);
}
uint16_t framenum(struct stack_frame* frame) {
	uint16_t frames = 0;
	while(frame != NULL) {
		frames++;
		frame = frame->old_frame;
	}
	return frames;
}
void stacktrace() {
	printf("--- Stacktrace ---\n");
	struct stack_frame* frame = current_frame;
	while(frame != NULL) {
		printf("   Frame %u\n",framenum(frame));
		printf("      PC: %p\n",frame->PC);
		printf("      Arguments passed: %u\n",frame->nargs);
		printf("      Return: %s.\n", frame->retvar ? "Yes" : "No");
		if(!(frame->stack == NULL || frame->stack[0] < 1)) {
			unsigned int count = 1;
			printf("      Stack:\n");
			for(uint16_t cell = frame->stack[0]; cell > 0; cell--)
				printf("         %04u: %u\n", count++, frame->stack[cell]);
		} else {
			printf("      Empty stack.\n");
		}
		if(!(frame->locals == NULL || frame->locals[0] < 1)) {
			printf("      Locals:\n");
			for(uint16_t cell = 1; cell <= frame->locals[0]; cell++)
				printf("          %01u: %u\n", cell, frame->locals[cell]);
		} else {
			printf("      No local variables.\n");
		}
		frame = frame->old_frame;
	}
	printf("--- End stacktrace ---\n");
}
