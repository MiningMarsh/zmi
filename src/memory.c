#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

uint8_t* RAM = NULL; // Holds the file.
// Globals and locals are pointers so that they can easily be stored on the
// stack.
struct stack_frame { // Holds the current routine state.
	struct stack_frame* old_frame;
	uint32_t PC;
	uint16_t* locals;
	uint16_t* stack;
	uint8_t retvar;
	uint8_t nargs;
};

struct stack_frame* CurrentZFrame;
int size;

void loadRAM(char* file)
{
	if(RAM != NULL)
	{
		free(RAM);
		RAM = NULL;
	}
	FILE* storyfile;
	storyfile = fopen(file, "rb");
	if(storyfile == NULL)
	{
		fputs("Error opening story file.\n",stderr);
		exit (1);
	}
	fseek(storyfile, 0, SEEK_END);
	int size = ftell(storyfile);
	rewind(storyfile);
	RAM = (int8_t*)malloc(sizeof(int8_t)*size);
	if(RAM == NULL)
	{
		fputs("Error allocating ram.\n",stderr);
		exit (1);
	}
	for(int i = 0; i < size; i++)
	{
		char buf[1];
		if(fread(buf, 1, 1, storyfile)!= 1)
		{
			fputs("Error reading story file.\n",stderr);
			exit(1);
		}
		RAM[i] = (uint8_t)buf[0];
	}
	size /= 1024;
	int maxsize;
	switch(RAM[0])
	{
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
	if(size > maxsize)
	{
		fputs("Story file too large.\n", stderr);
		exit (1);
	}
	fclose(storyfile);
}

// Get the word beginning at ram address adr.
uint16_t getWord(int adr)
{
	return RAM[adr+1]|(RAM[adr]<<8);
}

// Get the byte beginning at ram address adr.
uint8_t getByte(int adr)
{
	return RAM[adr];
}

// Get the current story file revision.
uint8_t getZRev() {
	return RAM[0];
}

// Set the word beginning at ram address adr to value.
void setWord(int adr, int16_t value)
{
	if(adr == 0)
	{
		fputs("Tried to set getZRev().\n",stderr);
		exit(1);
	}
	RAM[adr+1] = value&0xFF;
	RAM[adr] = (value>>8)&0xFF;
}

// Set the byte beginning at ram address adr to value.
void setByte(int adr, int8_t value)
{
	if(adr == 0)
	{
		fputs("Tried to set getZRev().\n",stderr);
		exit(1);
	}
	RAM[adr] = value&0xFF;
}

// Return the expanded packed address depending on the machine.
uint32_t exPadAdr(uint16_t padr)
{
	unsigned int machine = getByte(0);
	if(machine <= 3)
		return 2*padr;
	if(machine <=7)
		return 4*padr;
	return 8*padr;
}

// Pop from the stack.
uint16_t popZStack()
{
	if(CurrentZFrame->stack == NULL || CurrentZFrame->stack[0] < 1)
	{
		fputs("Tried POPing empty stack.\n", stderr);
		exit(1);
	}
	CurrentZFrame->stack[0]--;
	return CurrentZFrame->stack[CurrentZFrame->stack[0] + 1];
}
// Push to the stack.
void pushZStack(uint16_t val)
{
	if(CurrentZFrame->stack == NULL)
	{
		CurrentZFrame->stack = malloc(sizeof(uint16_t)*1024);
		CurrentZFrame->stack[0] = 0;
	}
	CurrentZFrame->stack[0]++;
	if(CurrentZFrame->stack == NULL)
	{
		fputs("Error PUSHing stack.\n", stderr);
		exit(1);
	}
	CurrentZFrame->stack[CurrentZFrame->stack[0]] = val;
}
// Get the value of variable reference var.
uint16_t getZVar(uint8_t var)
{
	if(var > 15)
		return getWord(getWord(0x06*2) + 2*(var - 16));
	return var > 0 ? CurrentZFrame->locals[var] : popZStack();
}
void setZVar(uint8_t var, uint16_t val) {
	if(var > 15)
		setWord(getWord(0x06*2) + 2*(var - 16), val);
	else if(var == 0)
		pushZStack(val);
	else
		CurrentZFrame->locals[var] = val;
}

// Push a copy of the current routine (stack frame).
void pushZFrame()
{
	struct stack_frame* new_frame = malloc(sizeof(struct stack_frame));
	if(new_frame == NULL)
	{
		fputs("Not enough memory to PUSH a stack frame.\n",stderr);
		exit(1);
	}
	new_frame->old_frame = CurrentZFrame;
	CurrentZFrame = new_frame;
	CurrentZFrame->locals = NULL;
	CurrentZFrame->stack = NULL;
	CurrentZFrame->retvar = 1;
}
// Pop a stack frame.
void popZFrame()
{
	if(CurrentZFrame->old_frame == NULL)
	{
		fputs("Attempted to POP main stack frame.\n", stderr);
		exit(1);
	}
	free(CurrentZFrame->locals);
	free(CurrentZFrame->stack);
	struct stack_frame* dead_frame = CurrentZFrame;
	CurrentZFrame = dead_frame->old_frame;
	free(dead_frame); //Summon Cthulhu to take the soul of the dead frame to the place of ultimate evil
}
uint16_t zFrameNumber(struct stack_frame* frame)
{
	uint16_t frames = 0;
	while(frame != NULL)
	{
		frames++;
		frame = frame->old_frame;
	}
	return frames;
}
void traceZStack()
{
	printf("--- Stacktrace ---\n");
	struct stack_frame* frame = CurrentZFrame;
	while(frame != NULL)
	{
		printf("   Frame %u\n",zFrameNumber(frame));
		printf("      PC: %u\n",frame->PC);
		printf("      Arguments passed: %u\n",frame->nargs);
		printf("      Return: %s.\n", frame->retvar ? "Yes" : "No");
		if(!(frame->stack == NULL || frame->stack[0] < 1))
		{
			unsigned int count = 1;
			printf("      Stack:\n");
			for(uint16_t cell = frame->stack[0]; cell > 0; cell--)
				printf("         %04u: %u\n", count++, frame->stack[cell]);
		} else
		{
			printf("      Empty stack.\n");
		}
		if(!(frame->locals == NULL || frame->locals[0] < 1))
		{
			printf("      Locals:\n");
			for(uint16_t cell = 1; cell <= frame->locals[0]; cell++)
				printf("          %01u: %u\n", cell, frame->locals[cell]);
		} else
		{
			printf("      No local variables.\n");
		}
		frame = frame->old_frame;
	}
	printf("--- End stacktrace ---\n");
}
