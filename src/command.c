#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "memory.h"
#include "input.h"
#include "output.h"
#include "exit.h"
#include "globalvars.h"
#include "log.h"
#include "command.h"
#include "opcodes.h"

// Holds arguments to opcodes.
uzword Operand[8];

// Used for easy identification of operand types.
enum operandType {
	LargeConstant = 0,
	SmallConstant = 1,
	Variable = 2,
	Omitted = 3
};

// Initiate the machine with a default set of values.
void initZM() {
	// Initiate input.
	initInput();
	// Initiate output.
	initOutput();

	// Clean if an error occurs, don't leave it to the OS. This may also display a Stacktrace and other debug things.
	atexit(clean);

	// Create the initial Stack frame.
	CurrentZFrame = malloc(sizeof(stackframe_t));
	if(CurrentZFrame == NULL) {
		logMessage(MFatal,"Initlization", "Not enough memory to create stack frame.");
		exit(1);
	}

	// Set up the values in the inital stack frame.
	// This is the first frame, so there is no previous frame.
	CurrentZFrame->OldFrame = NULL;
	// The initial PC is at 0x06.
	CurrentZFrame->PC = getWord(0x06);
	// First stack frame is not a routine, so no locals.
	CurrentZFrame->Locals = NULL;
	// Stack always starts out empty.
	CurrentZFrame->Stack = NULL;
	// Return value metadata, don't change this.
	CurrentZFrame->ReturnVar = 1;
	// The stack frame number, used for efficiency.
	CurrentZFrame->Depth = 0;

	// Populate the operation index.
	initOpCodes();

	// By this time, should be okay to clear the screen.
	printf("%c[2J,%c[0;0H",27,27);
}

// Execute an instruction begininng where the PC is currently pointing.
void execNextInstruction() {
	
	assert(CurrentZFrame->PC <= RAMSize);

	// Display a debug message.
	if(VerboseDebug >= 5) {
		logMessage(MNull, "Main loop", "Operation started.");
	}
	
	// Clean the operands by setting them all to omitted.
	uzbyte OperandType[8] = {
		Omitted, 
		Omitted,
		Omitted,
		Omitted,
		Omitted,
		Omitted,
		Omitted,
		Omitted
	};

	// Get the next operation and advance the PC.
	uzword Operation = getByte(CurrentZFrame->PC++);
	
	// Print the operation in debug mode.
	if(VerboseDebug >= 10) {
		printf("OP %u\n", Operation);
		logMessage(
			MNull, 
			NULL, 
			"PC: %u (%p) OP: %u (%p)", 
			CurrentZFrame->PC - 1, 
			(void*)(long)CurrentZFrame->PC - 1, 
			Operation,
		   	(void*)(long)Operation
		);
	}

   	// Extract argument types based on the opcode.
	if((Operation>>6) == 2) {
		// We are in short form. Bits 4 and 5 give the type.
		OperandType[0] = ((Operation >> 4) & 3);

	} else if(Operation>>6 == 3) {
		// Else we are either in extended form or variable form.
		
		// Holds the operation if we are in extended mode.
		uzbyte ExtendedOperation = 0;

		// If opcode is 190, and we are in revision 5 or greater, this is
		// an extended operation.
		if((Operation == 190) && (getZRev() > 4))
			// The next byte holds the extended operation.
			ExtendedOperation = (256 - 190) + getByte(CurrentZFrame->PC++);

		// Holds the operand types before they get extracted from the next 1-2 bytes.
		// the first value is set to any value, as it will always be replaced 
		// by the next byte. The second cell is set to 255 so that if only
		// 1 byte is provided, all its operand types resolve to omitted.
		uzbyte Args[2] = {0, 255};

		// Get the first packet of operands.
		Args[0] = getByte(CurrentZFrame->PC++);

		// For those to operands, grab a second packet of operands.
		if(Operation == 236 || Operation == 260) {
			Args[1] = getByte(CurrentZFrame->PC++);
		}

		OperandType[0] = Args[0] >> 6 & 3;
		OperandType[1] = Args[0] >> 4 & 3;
		OperandType[2] = Args[0] >> 2 & 3;
		OperandType[3] = Args[0] & 3;
		OperandType[4] = Args[1] >> 6 & 3;
		OperandType[5] = Args[1] >> 4 & 3;
		OperandType[6] = Args[1] >> 2 & 3;
		OperandType[7] = Args[1] & 3;

		// Add the extended operation offset if there is one.
		Operation += ExtendedOperation;
	} else {
		// We are in long form. Bits 6 and 5 hold the operand types. 
		OperandType[0] = ((Operation >> 6 & 1)+1);
		OperandType[1] = ((Operation >> 5 & 1)+1);
	}

	// Find the number of operands that have been extracted, then
	// populate them depending on their type. Print them if in debug mode.
	CurrentZFrame->PassedArgs = 8;
	for(int I = 0; I < 8; I++) {
		switch(OperandType[I]) {
			case Omitted:
				// If one operand is ommitted, so is all its followers.
				if(CurrentZFrame->PassedArgs > I)
					CurrentZFrame->PassedArgs = I;
				Operand[I] = 0;
				break;
			case LargeConstant:
				// Large constants are words.
				Operand[I] = getWord(CurrentZFrame->PC);
				CurrentZFrame->PC += 2;
				if(VerboseDebug >= 10) {
					logMessage(
						MNull, 
						"Operand", 
						"Large: %u (%p)", 
						Operand[I], 
						(void*)(long)Operand[I]
					);
				}
				break;
			case SmallConstant:
				// Small constants are bytes.
				Operand[I] = getByte(CurrentZFrame->PC++);
				if(VerboseDebug >= 10) {
					logMessage(
						MNull,
						"Operand",
						"Small: %u (%p)", 
						Operand[I], 
						(void*)(long)Operand[I]
					);
				}
				break;
			case Variable: {
				// Variable values are grabbed from memory.
				uint8_t Variable = getByte(CurrentZFrame->PC++);
				Operand[I] = getZVar(Variable);
				if(VerboseDebug >= 10) {
					logMessage(
						MNull,
						"Operand",
						"Var %u (%p): %u (%p)", 
						Variable, 
						(void*)(long)Variable, 
						Operand[I], 
						(void*)(long)Operand[I]
					);
				}
				break; }
		}
	}
	
	assert(CallOpCode[Operation]);
	
	// Execute the operation.
	CallOpCode[Operation]();
	if(VerboseDebug >= 5)
		logMessage(MNull, "Main loop", "Operation finished.\n");
}
