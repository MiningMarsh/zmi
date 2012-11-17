#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "memory.h"
#include "routine.h"
#include "object.h"
#include "zscii.h"
#include "input.h"
#include "output.h"
#include "exit.h"
#include "globalvars.h"
#include "log.h"

// Is this an extended operation code?
uint8_t IsExtOpCode = 0;

// Holds the operands to the operation being executed.
uint16_t Operand[8];

// Better than a switch. Each cell contains a pointer to a function to execute its opcode.
// callop[20]() executes operation 20.

// Used for easy identification of operand types.
enum operand_type {
	LargeConstant = 0,
	SmallConstant = 1,
	Variable = 2,
	Omitted = 3
};

// Include the operation code functions.
#include "opcodes.h"

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
		LogMessage(MFatal,"Initlization", "Not enough memory to create stack frame.");
		exit(1);
	}
	CurrentZFrame->OldFrame = NULL;
	CurrentZFrame->PC = getWord(0x06);
	CurrentZFrame->Locals = NULL;
	CurrentZFrame->Stack = NULL;
	CurrentZFrame->ReturnVar=1;

	// Populate the operation index.
	initOpCodes();
	for(int I = 0; I < 256; I++)
		if(!CallOpCode[I])
			CallOpCode[I] = &op_errnop;
	// By this time, should be okay to clear the screen.
	printf("%c[2J,%c[0;0H",27,27);
}

void execNextInstruction() {
	if( g_VerboseDebug >= 5)
	LogMessage(MNull, "Main loop", "Operation started.");
	// Clean the operands.
	uint8_t OperandType[8] = {
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
	uint8_t op = getByte(CurrentZFrame->PC++);
	// Print the operand in debug mode.
	if(g_VerboseDebug >= 10) {
		char Message[256];
		sprintf(Message,"PC: %5u OP: %3u", CurrentZFrame->PC - 1, op);
		LogMessage(MNull,"", Message);
	}
   	// Extract argument types based on the opcode.
	if(op < 128) {
		OperandType[0] = ((op >> 6 & 1)+1);
		OperandType[1] = ((op >> 5 & 1)+1);
	} else if(op < 192 && (op != 190)) {
		OperandType[0] = (op >> 4 & 3);
	} else {
		if(op == 190)
			IsExtOpCode = getByte(CurrentZFrame->PC++);
		int8_t args[2] = {0, 255};
		args[0] = getByte(CurrentZFrame->PC++);
		if(op == 236 || op == 260) {
			args[1] = getByte(CurrentZFrame->PC++);
		}
		OperandType[0] = args[0] >> 6 & 3;
		OperandType[1] = args[0] >> 4 & 3;
		OperandType[2] = args[0] >> 2 & 3;
		OperandType[3] = args[0] & 3;
		OperandType[4] = args[1] >> 6 & 3;
		OperandType[5] = args[1] >> 4 & 3;
		OperandType[6] = args[1] >> 2 & 3;
		OperandType[7] = args[1] & 3;
	}

	// Find the number of operands that have been extracted, then
	// populate them depending on their type. Print them if in debug mode.
	CurrentZFrame->PassedArgs = 8;
	for(int i = 0; i < 8; i++) {
		switch(OperandType[i]) {
			case Omitted:
				if(CurrentZFrame->PassedArgs > i)
					CurrentZFrame->PassedArgs = i;
				Operand[i] = 0;
				break;
			case LargeConstant:
				Operand[i] = getWord(CurrentZFrame->PC);
				CurrentZFrame->PC += 2;
				if(g_VerboseDebug >= 10) {
					char Message[256];
					sprintf(Message,"Large: %u", Operand[i]);
					LogMessage(MNull,"Operand", Message);
				}
				break;
			case SmallConstant:
				Operand[i] = getByte(CurrentZFrame->PC++);
				if(g_VerboseDebug >= 10) {
					char Message[256];
					sprintf(Message,"Small: %u", Operand[i]);
					LogMessage(MNull,"Operand", Message);
				}
				break;
			case Variable: {
				uint8_t var = getByte(CurrentZFrame->PC++);
				Operand[i] = getZVar(var);
				if(VerboseDebug >= 10) {
					char Message[256];
					sprintf(Message, "Var %u: %u", var, Operand[i]);
					LogMessage(MNull,"Operand", Message);
				}
				break; }
		}
	}
	// Execute the operation.
	CallOpCode[op]();
	if( g_VerboseDebug >= 5)
		LogMessage(MNull, "Main loop", "Operation finished.\n");
}
