#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"
#include "memory.h"
#include "globalvars.h"
#include "log.h"

uint8_t* RAM = NULL; // Holds the file.

void loadRAM(char* Filename)
{
	char* LogPrefix = "loadRAM()";
	char* Message = NULL;

	// Check if the ram is already been initilized. 
	if(RAM != NULL)
	{
		LogMessage(
			MFatal, 
			LogPrefix, 
			"Tried to load file while RAM is already initilized.\n"
			"This should NEVER happen, there is something seriously wrong."
		);
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
	RAM = (uint8_t*)malloc(sizeof(uint8_t)*g_StorySize);
	g_RAMSize = g_StorySize;
	if(!RAM)
	{
		sprintf(
			Message, 
			"Failed to allocate enough RAM to hold the story file.\n"
			"%u bytes are needed.",
			sizeof(int8_t)*g_RAMSize
		);
		LogMessage(MFatal, LogPrefix, Message);
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
		sprintf(Message, 
			"File is too large.\n"
			"Story is %ukb. Max size is %ukb.",
			g_StorySize,
			g_MaxStorySize
		);
		LogMessage(MFatal, LogPrefix, Message);
		exit (1);
	}
	fclose(StoryFile);
}

// Get the word beginning at ram address adr.
uint16_t getWord(const unsigned int Address) {
	if(Address+1 > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to grab word outside of memory: %p\n"
			"RAM is %u bytes.\n",
			(void*)Address,
			g_RAMSize
		);
		LogMessage(MFatal,"getWord()",Message);
		exit(1);
	}
	return RAM[Address+1]|(RAM[Address]<<8);
}

// Get the byte beginning at ram address adr.
uint8_t getByte(unsigned int Address)
{
	if(Address > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to grab byte outside of memory: %p\n"
			"RAM is %u bytes.\n",
			(void*)Address,
			g_RAMSize
		);
		LogMessage(MFatal,"getWord()",Message);
		exit(1);
	}
	return RAM[Address];
}

// Get the current story file revision.
uint8_t getZRev() {
	return RAM[0];
}

// Set the word beginning at ram address adr to value.
void setWord(unsigned int Address, int Value){
	if(!Address) {
		char  Message[256];
		sprintf(
			Message,
			"Tried to set byte 0 (Z-Revision) to %i.",
			Value
		);
		LogMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Address+1 > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set word outside of memory: %p\n"
			"RAM is %u bytes.\n",
			(void*)Address,
			g_RAMSize
		);
		LogMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Value > 0xFFFF) {
		LogMessage(MWarning,"setWord()","Truncating large word value.");
	}
	RAM[Address+1] = Value&0xFF;
	RAM[Address] = (Value>>8)&0xFF;
}

// Set the byte beginning at ram address adr to value.
void setByte(unsigned int Address, int Value)
{
	if(!Address) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set byte 0 (Z-Revision) to %i.",
			Value
		);
		LogMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Address > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set byte outside of memory: %p\n"
			"RAM is %u bytes.\n",
			(void*)Address,
			g_RAMSize
		);
		LogMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Value > 0xFF) {
		LogMessage(MWarning,"setByte()","Truncating large byte value.");
	}
	RAM[Address] = Value&0xFF;
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

// Pop from the Stack.
uint16_t popZStack()
{
	if(CurrentZFrame->Stack == NULL || CurrentZFrame->Stack[0] < 1)
	{
		fputs("Tried POPing empty Stack.\n", stderr);
		exit(1);
	}
	CurrentZFrame->Stack[0]--;
	return CurrentZFrame->Stack[CurrentZFrame->Stack[0] + 1];
}
// Push to the Stack.
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
		fputs("Error PUSHing Stack.\n", stderr);
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

// Push a copy of the current routine (Stack frame).
void pushZFrame()
{
	stackframe_t* new_frame = malloc(sizeof(stackframe_t));
	if(new_frame == NULL)
	{
		fputs("Not enough memory to PUSH a Stack frame.\n",stderr);
		exit(1);
	}
	new_frame->OldFrame = CurrentZFrame;
	CurrentZFrame = new_frame;
	CurrentZFrame->Locals = NULL;
	CurrentZFrame->Stack = NULL;
	CurrentZFrame->ReturnVar = 1;
}
// Pop a Stack frame.
void popZFrame()
{
	if(CurrentZFrame->OldFrame == NULL)
	{
		fputs("Attempted to POP main Stack frame.\n", stderr);
		exit(1);
	}
	free(CurrentZFrame->Locals);
	free(CurrentZFrame->Stack);
	stackframe_t* dead_frame = CurrentZFrame;
	CurrentZFrame = dead_frame->OldFrame;
	free(dead_frame); //Summon Cthulhu to take the soul of the dead frame to the place of ultimate evil
}
uint16_t zFrameNumber(stackframe_t* frame)
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
	LogMessage(MNull, "traceZStack()", "Begin Stacktrace.");
	stackframe_t* frame = CurrentZFrame;
	while(frame != NULL)
	{
		char Message[256];
		sprintf(Message,"   Frame %u",zFrameNumber(frame));
		LogMessage(MNull,NULL,Message);
		sprintf(Message, "      PC: %u",frame->PC);
		LogMessage(MNull,NULL,Message);
		sprintf(Message, "      Arguments passed: %u",frame->PassedArgs);
		LogMessage(MNull,NULL,Message);
		sprintf(Message, "      Return: %s.", frame->ReturnVar ? "Yes" : "No");
		LogMessage(MNull,NULL,Message);
		if(!(frame->Stack == NULL || frame->Stack[0] < 1))
		{
			unsigned int count = 1;
			LogMessage(MNull, NULL, "      Stack:");
			for(uint16_t cell = frame->Stack[0]; cell > 0; cell--) {
				sprintf(Message, "         %04u: %u", count++, frame->Stack[cell]);
				LogMessage(MNull, NULL, Message);
			}
		} else
		{
			LogMessage(MNull,NULL,"      Empty Stack.");
		}
		if(!(frame->Locals == NULL || frame->Locals[0] < 1))
		{
			LogMessage(MNull, NULL, "      Locals:");
			for(uint16_t cell = 1; cell <= frame->Locals[0]; cell++) {
				sprintf(Message, "          %01u: %u", cell, frame->Locals[cell]);
				LogMessage(MNull,NULL,Message);
			}
		} else
		{
			LogMessage(MNull, NULL, "      No local variables.");
		}
		frame = frame->OldFrame;
	}
	LogMessage(MNull, "traceZStack()", "End Stacktrace.");
}
