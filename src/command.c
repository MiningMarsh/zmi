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
void (*CallOpCode[256])(void) = {NULL};

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
	for(int I = 0; I < 256; I++)
		CallOpCode[I] = &op_errnop;
	for(int I = 0; I < 7; I++) {
		CallOpCode[1+32*I] = &op_je;
		CallOpCode[2+32*I] = &op_jl;
		CallOpCode[3+32*I] = &op_jg;
		CallOpCode[4+32*I] = &op_dec_chk;
		CallOpCode[5+32*I] = &op_inc_chk;
		CallOpCode[6+32*I] = &op_jin;
		CallOpCode[7+32*I] = &op_test;
		CallOpCode[8+32*I] = &op_or;
		CallOpCode[9+32*I] = &op_and;
		CallOpCode[10+32*I] = &op_test_attr;
		CallOpCode[11+32*I] = &op_set_attr;
		CallOpCode[12+32*I] = &op_clear_attr;
		CallOpCode[13+32*I] = &op_store;
		CallOpCode[14+32*I] = &op_insert_obj;
		CallOpCode[15+32*I] = &op_loadw;
		CallOpCode[16+32*I] = &op_loadb;
		CallOpCode[17+32*I] = &op_get_prop;
		CallOpCode[18+32*I] = &op_get_prop_addr;
		CallOpCode[20+32*I] = &op_add;
		CallOpCode[21+32*I] = &op_sub;
		CallOpCode[22+32*I] = &op_mul;
		CallOpCode[23+32*I] = &op_div;
		CallOpCode[24+32*I] = &op_mod;
		if(getZRev() >= 4)
			CallOpCode[25+32*I] = &op_call;
		if(getZRev() >= 5)
			CallOpCode[26+32*I] = &op_call_throw;
		if(getZRev() == 5 || getZRev() == 6)
			CallOpCode[28+32*I] = &op_throw;
	}
	for(int I = 0; I  < 32; I++) {
		CallOpCode[I+32*4] = &op_errnop;
		CallOpCode[I+32*5] = &op_errnop;
	}
	for(int I = 0; I < 3; I++) {
		CallOpCode[128+16*I] = &op_jz;
		CallOpCode[129+16*I] = &op_get_sibling;
		CallOpCode[130+16*I] = &op_get_child;
		CallOpCode[131+16*I] = &op_get_parent;
		CallOpCode[133+16*I] = &op_inc;
		CallOpCode[134+16*I] = &op_dec;
		if(getZRev() >= 4)
			CallOpCode[136+16*I] = &op_call;
		CallOpCode[138+16*I] = &op_print_obj;
		CallOpCode[139+16*I] = &op_ret;
		CallOpCode[140+16*I] = &op_jump;
		CallOpCode[141+16*I] = &op_print_paddr;
		CallOpCode[176+16*I] = &op_rtrue;
		CallOpCode[177+16*I] = &op_rfalse;
		CallOpCode[178+16*I] = &op_print;
		CallOpCode[184+16*I] = &op_ret_popped;
		CallOpCode[187+16*I] = &op_new_line;
	}
	CallOpCode[224] = &op_call;
	CallOpCode[225] = &op_storew;
	CallOpCode[226] = &op_storeb;
	CallOpCode[227] = &op_put_prop;
	CallOpCode[228] = &op_read;
	CallOpCode[229] = &op_print_char;
	CallOpCode[230] = &op_print_num;
	CallOpCode[231] = &op_random;
	CallOpCode[232] = &op_push;
	CallOpCode[233] = &op_pull;
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
