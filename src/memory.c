#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "globalvars.h"
#include "log.h"
#include "zint.h"

uzbyte* RAM = NULL; // Holds the file.

// Load a story file into memory.
void loadRAM(const char* const Filename) {
	
	// The prefix all log messages will have.

	// Check if the ram is already been initilized. 
	if(RAM != NULL) {
		log_Message(
			MFatal, 
			"loadRAM()", 
			"Tried to load file while RAM is already initialized.\n"
			"This should NEVER happen, there is something seriously wrong."
		);
		exit(1);
	}

	// File pointer to the story.
	FILE* StoryFile;
	StoryFile = fopen(Filename, "rb");
	if(StoryFile == NULL) {
		fputs(ProgramName, stderr);
		fputs(": ", stderr);
		perror(Filename);
		exit (1);
	}
	// Read the story file size.
	fseek(StoryFile, 0, SEEK_END);
	StorySize = ftell(StoryFile);
	rewind(StoryFile);

	// Allocate the ram.
	RAM = (uzbyte*)malloc(sizeof(uzbyte)*StorySize);
	RAMSize = StorySize;

	// Check if we ran out of memory allocating RAM.
	if(!RAM) {
		log_Message(
			MFatal, 
			"loadRAM()", 
			"Failed to allocate enough RAM to hold the story file.\n"
			"%u bytes are needed.",
			(unsigned int)sizeof(uzbyte)*RAMSize
		);
		exit (1);
	}

	// Read the file into the RAM.
	if(fread(RAM, sizeof(uzbyte), StorySize, StoryFile) != StorySize) {
			log_Message(MFatal, "loadRAM()", "Failed to read file.");
			exit(1);
	}
	
	// There is no standard above revision 8.
	if(getZRev() > 8) {
		log_Message(
			MFatal, 
			"loadRAM()", 
			"Bad Z-Revision: %u.",
			getZRev()
		);
		exit (1);
	}

	// Make sure the story file was not too large.
	switch(RAM[0]) {
		case 1:
		case 2:
		case 3:
			MaxStorySize = 128;
			break;
		case 4:
		case 5:
			MaxStorySize = 256;
			break;
		case 7:
			MaxStorySize = 320;
			break;
		case 6:
		case 8:
			MaxStorySize = 512;
			break;
	}
	// The size is in KiB, convert into bytes.
	MaxStorySize *= 1024;
	// Check actual story size against max story size.
	if(StorySize > MaxStorySize) {
		log_Message(
			MFatal, 
			"loadRAM()", 
			"File is too large.\n"
			"Story is %ukb. Max size is %ukb.",
			StorySize / 1024,
			MaxStorySize / 1024
		);
		exit (1);
	}
	// We no longer need access to the file.
	fclose(StoryFile);
}

// Get the word beginning at ram address adr.
uzword getWord(const zaddress Address) {
	// The address is out of bounds of RAM.
	if(Address+1 > RAMSize) {
		log_Message(
			MFatal,
			"getWord()",
			"Tried to grab word outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			RAMSize
		);
		exit(1);
	}
	return RAM[Address+1]|(RAM[Address]<<8);
}

// Get the byte beginning at ram address adr.
uzbyte getByte(const zaddress Address) {
	// Error is the address is out of bounds of RAM.
	if(Address > RAMSize) {
		log_Message(
			MFatal,
			"getWord()",
			"Tried to grab byte outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			RAMSize
		);
		exit(1);
	}
	return RAM[Address];
}

// Get the current story file revision.
uzbyte getZRev() {
	return getByte(0);
}

// Set the word beginning at ram address adr to value.
void setWord(const zaddress Address, const uzword Value) {
	if(!Address) {
		log_Message(
			MFatal,
			"setWord()",
			"Tried to set word 0 (Z-Revision) to %u.",
			Value
		);
		exit(1);
	} else if(Address+1 > RAMSize) {
		log_Message(
			MFatal,
			"setWord()",
			"Tried to set word outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			RAMSize
		);
		exit(1);
	}
	RAM[Address+1] = Value&0xFF;
	RAM[Address] = (Value>>8)&0xFF;
}

// Set the byte beginning at ram address adr to value.
void setByte(const zaddress Address, const uzbyte Value) {
	if(!Address) {
		log_Message(
			MFatal,
			"setWord()",
			"Tried to set byte 0 (Z-Revision) to %u.",
			Value
		);
		exit(1);
	} else if(Address > RAMSize) {
		log_Message(
			MFatal,
			"setWord()",
			"Tried to set byte outside of memory: %u\n"
			"RAM is %u bytes.\n",
			Address,
			RAMSize
		);
		exit(1);
	}
	RAM[Address] = Value&0xFF;
}

// Return the expanded packed address depending on the machine.
zaddress expandPaddedAddress(const uzword PaddedAddress) {
	switch(getZRev()) {
		case 1:
		case 2:
		case 3:
			return 2*PaddedAddress;
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			return 4*PaddedAddress;
			break;
		case 8:
			return 8*PaddedAddress;
			break;
	}
	return 0;
}

// Pop from the Stack.
uzword popZStack() {
	if(CurrentZFrame->Stack == NULL || CurrentZFrame->Stack[0] < 1) {
		log_Message(
			MFatal, 
			"popZStack()", 
			"Tried to POP an empty stack."
		);
		exit(1);
	}
	CurrentZFrame->Stack[0]--;
	return CurrentZFrame->Stack[CurrentZFrame->Stack[0] + 1];
}

// Push to the Stack.
void pushZStack(const uzword Value) {
	
	// If there is no stack allocated yet, allocate one.
	if(CurrentZFrame->Stack == NULL) {
		// For speed, we have a hard limit of 1024 bytes on the stack. Other
		// interpreters implement this already, and we will increase it if it
		// ever becomes a problem. Or just make an unlimited size stack.
		CurrentZFrame->Stack = malloc(sizeof(uzword)*1024);
		if(CurrentZFrame->Stack) {
			// Init stack.
			CurrentZFrame->Stack[0] = 0;
			
		}
	
	// If we already have a stack, check to make sure we are not overflowing 
	// it.
	} else if(CurrentZFrame->Stack[0] >= 1023) {
		free(CurrentZFrame->Stack);
		CurrentZFrame->Stack = NULL;
	}

	// Check to make sure stack is sane.
	if(CurrentZFrame->Stack == NULL) {
		log_Message(
			MFatal, 
			"pushZStack()", 
			"Ran out of memory while PUSHing to the stack"
		);
		exit(1);
	}

	// Put the passed value on the stack.
	CurrentZFrame->Stack[0]++;
	CurrentZFrame->Stack[CurrentZFrame->Stack[0]] = Value;
}

// Get the value of variable reference Variable.
uzword getZVar(const uzbyte Variable) {
	// Variable numbers above 15 are global variables.
	if(Variable > 15)
		return getWord(getWord(0x06*2) + 2*(Variable - 16));
	// Variable number 0 is the stack, variable numbers 1-15 are local variables.
	else 
		return Variable > 0 ? CurrentZFrame->Locals[Variable] : popZStack();
}

// Set the value of a variable reference Variable.
void setZVar(const uzbyte Variable, const uzword Value) {
	// Variable numbers above 15 are global variables.
	if(Variable > 15)
		setWord(getWord(0x06*2) + 2*(Variable - 16), Value);
	// Variable number 0 is the stack.
	else if(Variable == 0)
		pushZStack(Value);
	// Variable numbers 1-15 are local variables.
	else
		CurrentZFrame->Locals[Variable] =Value;
}

// Push a copy of the current routine state (Stack frame).
void pushZFrame() {
	stackframe_t* NewFrame = malloc(sizeof(stackframe_t));
	if(NewFrame == NULL) {
		log_Message(
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
		log_Message(MFatal, "popZFrame()", "Tried to POP the main stack frame.");
		exit(1);
	}
	free(CurrentZFrame->Locals);
	free(CurrentZFrame->Stack);
	stackframe_t* DeadFrame = CurrentZFrame;
	CurrentZFrame = DeadFrame->OldFrame;
	// Summon Cthulhu to take the soul of the dead frame to the place of ultimate
	// evil.
	free(DeadFrame); 
}

// Return the current stack depth.
uzword zFrameNumber(const stackframe_t* Frame) {
	return Frame->Depth;
}

// Log a stack trace.
void traceZStack() {
	char* Prefix = "tZS()";
	log_Message(
		MNull, 
		Prefix, 
		"Begin Stacktrace."
	);
	stackframe_t* Frame = CurrentZFrame;
	while(Frame != NULL) {
		log_Message(
			MNull, 
			NULL,
			"   Frame %u",
			"      PC: %u",
			"      Arguments passed: %u",
			"      Return: %s.", 
			zFrameNumber(Frame),
			Frame->PC,
			Frame->PassedArgs,
			Frame->ReturnVar ? "Yes" : "No"
		);
		if(!(Frame->Stack == NULL || Frame->Stack[0] < 1)) {
			unsigned int Count = 1;
			log_Message(
				MNull, 
				NULL, 
				"      Stack:"
			);
			for(uzword Cell = Frame->Stack[0]; Cell > 0; Cell--) {
				log_Message(
					MNull, 
					NULL, 
					"         %04u: %u", 
					Count++, 
					Frame->Stack[Cell]
				);
			}
		} else {
			log_Message(
				MNull, 
				NULL,
				"      Empty Stack."
			);
		}
		if(!(Frame->Locals == NULL || Frame->Locals[0] < 1)) {
			log_Message(
				MNull, 
				NULL, 
				"      Locals:"
			);
			for(uzword Cell = 1; Cell <= Frame->Locals[0]; Cell++) {
				log_Message(
					MNull, 
					NULL, 
					"         %02u: %u", 
					Cell, 
					Frame->Locals[Cell]
				);
			}
		} else {
			log_Message(
				MNull, 
				NULL, 
				"      No local variables."
			);
		}
		Frame = Frame->OldFrame;
	}
	log_Message(
		MNull, 
		Prefix, 
		"End Stacktrace."
	);
}
