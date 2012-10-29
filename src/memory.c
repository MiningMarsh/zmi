#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"
#include "memory.h"
#include "log.h"

uint8_t* RAM = NULL; // Holds the file.

void loadRAM(char* Filename)
{
	const char* LogPrefix = "loadRAM()";

	// Check if the ram is already been initilized. 
	if(RAM != NULL)
	{
		LogMessage(MFatal, LogPrefix, "Tried to load file while live.\n");
		exit(1);
	}
	// File pointer to the story.
	FILE* StoryFile;
	StoryFile = fopen(Filename, "rb");
	if(StoryFile == NULL)
	{
		perror(Filename);
		exit (1);
	}
	fseek(StoryFile, 0, SEEK_END);
	g_StorySize = ftell(StoryFile);
	rewind(StoryFile);
	RAM = (int8_t*)malloc(sizeof(int8_t)*g_StorySize);
	g_RAMSize = g_StorySize
	if(RAM == NULL)
	{
		LogMessage(MFatal, LogPrefix, "Failed to allocate RAM.");
		exit (1);
	}
 	for(int i = 0; i < g_StorySize; i++)
	{
		char Buffer[1];
		if(fread(Buffer, 1, 1, StoryFile)!= 1)
		{
			LogMessage(MFatal, LogPrefix, "Failed to read file.");
			exit(1);
		}
		RAM[i] = (uint8_t)Buffer[0];
	}
	g_StorySize /= 1024;
	switch(RAM[0])
	{
		case 1:
		case 2:
		case 3:
			g_MaxStorySize = 128;
			break;
		case 4:
		case 5:
			g_MaxStorySize = 256;
			break;
		case 7:
			g_MaxStorySize = 320;
			break;
		case 6:
		case 8:
			g_MaxStorySize = 512;
			break;
	}
	if(g_StorySize > g_MaxStorySize)
	{
		LogMessage(MWarning, LogPrefix, "File larger than allowed by standard.");
		exit (1);
	}
	fclose(StoryFile);
}

// Get the word beginning at ram address adr.
uint16_t getWord(unsigned int Address)
{
	if(Address+1 > g_RAMSize) {
		char* ErrMessage;
		sprintf(
			ErrMessage,
			"FATAL: tried to grab word outside of memory: %p\n"
			"FATAL: RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		fputs(ErrMessage,stderr);
		free(ErrMessage);
		exit(1);
	}
	return RAM[adr+1]|(RAM[adr]<<8);
}

// Get the byte beginning at ram address adr.
uint8_t getByte(unsigned int adr)
{
	if(Address > g_RAMSize) {
		char* ErrMessage;
		sprintf(
			ErrMessage,
			"FATAL: tried to grab byte outside of memory: %p\n"
			"FATAL: RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		fputs(ErrMessage,stderr);
		free(ErrMessage);
		exit(1);
	}
	return RAM[adr];
}

// Get the current story file revision.
uint8_t getZRev() {
	return RAM[0];
}

// Set the word beginning at ram address adr to value.
void setWord(unsigned int Address, int Value)
{
	if(!Address) {
		char* ErrMessage;
		sprintf(
			ErrMessage,
			"FATAL: tried to set Z-Revision to %i.\n"
			Value
		);
		fputs(ErrMessage,stderr);
		free(ErrMessage);
		exit(1);
	}
	if(Value > 0xFFFF) {
		fputs("WARNING: Setting a word to a value greater tha
	}
	RAM[Address+1] = Value&0xFF;
	RAM[Address] = (Value>>8)&0xFF;
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
	if(CurrentZFrame->Stack == NULL || CurrentZFrame->sSack[0] < 1)
	{
		fputs("Tried POPing empty stack.\n", stderr);
		exit(1);
	}
	CurrentZFrame->Stack[0]--;
	return CurrentZFrame->Stack[CurrentZFrame->Stack[0] + 1];
}
// Push to the stack.
void pushZStack(uint16_t val)
{
	if(CurrentZFrame->Stack == NULL)
	{
		CurrentZFrame->Stack = malloc(sizeof(uint16_t)*1024);
		CurrentZFrame->Stack[0] = 0;
	}
	CurrentZFrame->Stack[0]++;
	if(CurrentZFrame->Stack == NULL)
	{
		fputs("Error PUSHing stack.\n", stderr);
		exit(1);
	}
	CurrentZFrame->Stack[CurrentZFrame->Stack[0]] = val;
}
// Get the value of variable reference var.
uint16_t getZVar(uint8_t var)
{
	if(var > 15)
		return getWord(getWord(0x06*2) + 2*(var - 16));
	return var > 0 ? CurrentZFrame->Locals[var] : popZStack();
}
void setZVar(uint8_t var, uint16_t val) {
	if(var > 15)
		setWord(getWord(0x06*2) + 2*(var - 16), val);
	else if(var == 0)
		pushZStack(val);
	else
		CurrentZFrame->Locals[var] = val;
}

// Push a copy of the current routine (stack frame).
void pushZFrame()
{
	stackframe_t* new_frame = malloc(sizeof(stackframe_t));
	if(new_frame == NULL)
	{
		fputs("Not enough memory to PUSH a stack frame.\n",stderr);
		exit(1);
	}
	new_frame->OldFrame = CurrentZFrame;
	CurrentZFrame = new_frame;
	CurrentZFrame->Locals = NULL;
	CurrentZFrame->Stack = NULL;
	CurrentZFrame->ReturnVar = 1;
}
// Pop a stack frame.
void popZFrame()
{
	if(CurrentZFrame->OldFrame == NULL)
	{
		fputs("Attempted to POP main stack frame.\n", stderr);
		exit(1);
	}
	free(CurrentZFrame->locals);
	free(CurrentZFrame->stack);
	stackframe_t* dead_frame = CurrentZFrame;
	CurrentZFrame = dead_frame->OldFrame;
	free(dead_frame); //Summon Cthulhu to take the soul of the dead frame to the place of ultimate evil
}
uint16_t zFrameNumber(struct stack_frame* frame)
{
	uint16_t frames = 0;
	while(frame != NULL)
	{
		frames++;
		frame = frame->OldFrame;
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
		printf("      Arguments passed: %u\n",frame->);
		printf("      Return: %s.\n", frame->ReturnVar ? "Yes" : "No");
		if(!(frame->stack == NULL || frame->Stack[0] < 1))
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
