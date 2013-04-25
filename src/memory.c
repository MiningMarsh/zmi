#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "globalvars.h"
#include "log.h"
#include "zint.h"

uzbyte* RAM = NULL; // Holds the file.

// Load a story file into memory.
void loadRAM(const char* const Filename) {
	char* LogPrefix = "loadRAM()";
	char* Message = NULL;

	// Check if the ram is already been initilized. 
	if(RAM != NULL) {
		logMessage(
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
	if(StoryFile == NULL) {
		fputs(g_ProgramName, stderr);
		fputs(": ", stderr);
		perror(Filename);
		exit (1);
	}
	// Read the story file size.
	fseek(StoryFile, 0, SEEK_END);
	g_StorySize = ftell(StoryFile);
	rewind(StoryFile);
	RAM = (uzbyte*)malloc(sizeof(uzbyte)*g_StorySize);
	g_RAMSize = g_StorySize;

	// Check if we ran out of memory allocating RAM.
	if(!RAM) {
		sprintf(
			Message, 
			"Failed to allocate enough RAM to hold the story file.\n"
			"%u bytes are needed.",
			(unsigned int)sizeof(uzbyte)*g_RAMSize
		);
		logMessage(MFatal, LogPrefix, Message);
		exit (1);
	}
	if(fread(RAM, sizeof(uzbyte), g_StorySize, StoryFile) != g_StorySize) {
			logMessage(MFatal, LogPrefix, "Failed to read file.");
			exit(1);
	}

	// Make sure the story fil was not too large.
	switch(RAM[0]) {
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
	g_MaxStorySize *= 1024;
	if(g_StorySize > g_MaxStorySize) {
		sprintf(Message, 
			"File is too large.\n"
			"Story is %ukb. Max size is %ukb.",
			g_StorySize / 1024,
			g_MaxStorySize / 1024
		);
		logMessage(MFatal, LogPrefix, Message);
		exit (1);
	}
	fclose(StoryFile);
}

// Get the word beginning at ram address adr.
uzword getWord(const unsigned int Address) {
	// Error is the address is out of bounds of RAM.
	if(Address+1 > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to grab word outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		logMessage(MFatal,"getWord()",Message);
		exit(1);
	}
	return RAM[Address+1]|(RAM[Address]<<8);
}

// Get the byte beginning at ram address adr.
uzbyte getByte(const unsigned int Address) {
	// Error is the address is out of bounds of RAM.
	if(Address > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to grab byte outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		logMessage(MFatal,"getWord()",Message);
		exit(1);
	}
	return RAM[Address];
}

// Get the current story file revision.
uzbyte getZRev() {
	return getByte(0);
}

// Set the word beginning at ram address adr to value.
void setWord(const unsigned int Address, const uzword Value) {
	if(!Address) {
		char  Message[256];
		sprintf(
			Message,
			"Tried to set byte 0 (Z-Revision) to %u.",
			Value
		);
		logMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Address+1 > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set word outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		logMessage(MFatal,"setWord()",Message);
		exit(1);
	}
	RAM[Address+1] = Value&0xFF;
	RAM[Address] = (Value>>8)&0xFF;
}

// Set the byte beginning at ram address adr to value.
void setByte(const unsigned int Address, const uzbyte Value) {
	if(!Address) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set byte 0 (Z-Revision) to %u.",
			Value
		);
		logMessage(MFatal,"setWord()",Message);
		exit(1);
	} else if(Address > g_RAMSize) {
		char Message[256];
		sprintf(
			Message,
			"Tried to set byte outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			g_RAMSize
		);
		logMessage(MFatal,"setWord()",Message);
		exit(1);
	}
	RAM[Address] = Value&0xFF;
}

// Return the expanded packed address depending on the machine.
uzword expandPaddedAddress(const uzword PaddedAddress) {
	if(getZRev() <= 3)
		return 2*PaddedAddress;
	else if(getZRev() <=7)
		return 4*PaddedAddress;
	else 
		return 8*PaddedAddress;
}

// Pop from the Stack.
uzword popZStack() {
	if(CurrentZFrame->Stack == NULL || CurrentZFrame->Stack[0] < 1) {
		logMessage(MFatal, "popZStack()", "Tried to POP an empty stack.");
		exit(1);
	}
	CurrentZFrame->Stack[0]--;
	return CurrentZFrame->Stack[CurrentZFrame->Stack[0] + 1];
}

// Push to the Stack.
void pushZStack(const uzword Value) {
	if(CurrentZFrame->Stack == NULL) {
		CurrentZFrame->Stack = malloc(sizeof(uzword)*1024);
		CurrentZFrame->Stack[0] = 0;
	}
	CurrentZFrame->Stack[0]++;
	if(CurrentZFrame->Stack == NULL) {
		logMessage(
			MFatal, 
			"pushZStack()", 
			"Ran out of memory while PUSHing to the stack"
		);
		exit(1);
	}
	CurrentZFrame->Stack[CurrentZFrame->Stack[0]] = Value;
}

// Get the value of variable reference Variable.
uzword getZVar(const uzbyte Variable) {
	if(Variable > 15)
		return getWord(getWord(0x06*2) + 2*(Variable - 16));
	else 
		return Variable > 0 ? CurrentZFrame->Locals[Variable] : popZStack();
}

// Set the value of a variable reference Variable.
void setZVar(const uzbyte Variable, const uzword Value) {
	if(Variable > 15)
		setWord(getWord(0x06*2) + 2*(Variable - 16), Value);
	else if(Variable == 0)
		pushZStack(Value);
	else
		CurrentZFrame->Locals[Variable] =Value;
}

// Push a copy of the current routine (Stack frame).
void pushZFrame() {
	stackframe_t* NewFrame = malloc(sizeof(stackframe_t));
	if(NewFrame == NULL) {
		logMessage(
			MFatal, 
			"pushZFrame()", 
			"Ran out of memory while PUSHing a new stack frame."
		);
		exit(1);
	}
	NewFrame->OldFrame = CurrentZFrame;
	CurrentZFrame = NewFrame;
	CurrentZFrame->Depth = CurrentZFrame->OldFrame->Depth + 1;
	CurrentZFrame->Locals = NULL;
	CurrentZFrame->Stack = NULL;
	CurrentZFrame->ReturnVar = 1;
}

// Pop a Stack frame.
void popZFrame() {
	if(CurrentZFrame->OldFrame == NULL) {
		logMessage(MFatal, "popZFrame()", "Tried to POP the main stack frame.");
		exit(1);
	}
	free(CurrentZFrame->Locals);
	free(CurrentZFrame->Stack);
	stackframe_t* DeadFrame = CurrentZFrame;
	CurrentZFrame = DeadFrame->OldFrame;
	//Summon Cthulhu to take the soul of the dead frame to the place of ultimate
	// evil.
	free(DeadFrame); 
}

uzword zFrameNumber(const stackframe_t* Frame) {
	return Frame->Depth;
}

void traceZStack() {
	char* Prefix = "tZS()";
	logMessage(
		MNull, 
		Prefix, 
		"Begin Stacktrace."
	);
	stackframe_t* Frame = CurrentZFrame;
	while(Frame != NULL) {
		char Message[256];
		sprintf(
			Message,
			"   Frame %u",
			zFrameNumber(Frame)
		);
		logMessage(
			MNull, 
			NULL,
			Message
		);
		sprintf(
			Message, 
			"      PC: %u (%p)",
			Frame->PC, 
			(void*)Frame->PC
		);
		logMessage(
			MNull,
			NULL,
			Message
		);
		sprintf(
			Message, 
			"      Arguments passed: %u",
			Frame->PassedArgs
		);
		logMessage(
			MNull,
			NULL,
			Message
		);
		sprintf(
			Message, 
			"      Return: %s.", 
			Frame->ReturnVar ? "Yes" : "No"
		);
		logMessage(
			MNull, 
			NULL, 
			Message
		);
		if(!(Frame->Stack == NULL || Frame->Stack[0] < 1)) {
			unsigned int Count = 1;
			logMessage(
				MNull, 
				NULL, 
				"      Stack:"
			);
			for(uzword Cell = Frame->Stack[0]; Cell > 0; Cell--) {
				sprintf(
					Message, 
					"         %04u: %u (%p)", 
					Count++, 
					Frame->Stack[Cell], 
					(void*)Frame->Stack[Cell]
				);
				logMessage(
					MNull, 
					NULL, 
					Message
				);
			}
		} else {
			logMessage(
				MNull, 
				NULL,
				"      Empty Stack."
			);
		}
		if(!(Frame->Locals == NULL || Frame->Locals[0] < 1)) {
			logMessage(
				MNull, 
				NULL, 
				"      Locals:"
			);
			for(uzword Cell = 1; Cell <= Frame->Locals[0]; Cell++) {
				sprintf(
					Message, 
					"          %01u: %u (%p)", 
					Cell, 
					Frame->Locals[Cell], 
					(void*)Frame->Locals[Cell]
				);
				logMessage(
					MNull, 
					NULL, 
					Message
				);
			}
		} else {
			logMessage(
				MNull, 
				NULL, 
				"      No local variables."
			);
		}
		Frame = Frame->OldFrame;
	}
	logMessage(
		MNull, 
		Prefix, 
		"End Stacktrace."
	);
}
