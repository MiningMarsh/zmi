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


// TODO: Still not resolving getZRev() properly

// Is this an extended operation code?
uint8_t extop = 0;

// Holds the operands to the operation being executed.
uint16_t operand[8];

// Better than a switches. Each cell contains a pointer to a function to execute its opcode. callop[20]() executes operation 20.
void (*callop[256])(void) = {NULL};

// Used for easy identification of operand types.
enum OperandType {
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
	initin();
	// Initiate output.
	initout();
	// Clean if an error occurs, don't leave it to the OS. This may also display a stacktrace and other debug things.
	atexit(clean);
	// Create the initial stack frame.
	current_frame = malloc(sizeof(struct stack_frame));
	if(current_frame == NULL) {
		fputs("Unable to allocate first frame.\n", stderr);
		exit(1);
	}
	current_frame->old_frame = NULL;
	current_frame->PC = getWord(0x06);
	current_frame->locals = NULL;
	current_frame->stack = NULL;
	current_frame->retvar=1;

	// Populate the operation index.
	for(int i = 0; i < 256; i++)
		callop[i] = &op_errnop;
	for(int i = 0; i < 7; i++) {
		callop[1+32*i] = &op_je;
		callop[2+32*i] = &op_jl;
		callop[3+32*i] = &op_jg;
		callop[4+32*i] = &op_dec_chk;
		callop[5+32*i] = &op_inc_chk;
		callop[6+32*i] = &op_jin;
		callop[7+32*i] = &op_test;
		callop[8+32*i] = &op_or;
		callop[9+32*i] = &op_and;
		callop[10+32*i] = &op_test_attr;
		callop[11+32*i] = &op_set_attr;
		callop[12+32*i] = &op_clear_attr;
		callop[13+32*i] = &op_store;
		callop[14+32*i] = &op_insert_obj;
		callop[15+32*i] = &op_loadw;
		callop[16+32*i] = &op_loadb;
		callop[17+32*i] = &op_get_prop;
		callop[18+32*i] = &op_get_prop_addr;
		callop[20+32*i] = &op_add;
		callop[21+32*i] = &op_sub;
		callop[22+32*i] = &op_mul;
		callop[23+32*i] = &op_div;
		callop[24+32*i] = &op_mod;
		if(getZRev() >= 4)
			callop[25+32*i] = &op_call;
		if(getZRev() >= 5)
			callop[26+32*i] = &op_call_throw;
		if(getZRev() == 5 || getZRev() == 6)
			callop[28+32*i] = &op_throw;
	}
	for(int i = 0; i  < 32; i++) {
		callop[i+32*4] = &op_errnop;
		callop[i+32*5] = &op_errnop;
	}
	for(int i = 0; i < 3; i++) {
		callop[128+16*i] = &op_jz;
		callop[129+16*i] = &op_get_sibling;
		callop[130+16*i] = &op_get_child;
		callop[131+16*i] = &op_get_parent;
		callop[133+16*i] = &op_inc;
		callop[134+16*i] = &op_dec;
		if(getZRev() >= 4)
			callop[136+16*i] = &op_call;
		callop[138+16*i] = &op_print_obj;
		callop[139+16*i] = &op_ret;
		callop[140+16*i] = &op_jump;
		callop[141+16*i] = &op_print_paddr;
		callop[176+16*i] = &op_rtrue;
		callop[177+16*i] = &op_rfalse;
		callop[178+16*i] = &op_print;
		callop[184+16*i] = &op_ret_popped;
		callop[187+16*i] = &op_new_line;
	}
	callop[224] = &op_call;
	callop[225] = &op_storew;
	callop[226] = &op_storeb;
	callop[227] = &op_put_prop;
	callop[228] = &op_read;
	callop[229] = &op_print_char;
	callop[230] = &op_print_num;
	callop[232] = &op_push;
	callop[233] = &op_pull;
	// By this time, should be okay to clear the screen.
	printf("%c[2J,%c[0;0H",27,27);
}

void execNextInstruction() {
	// Clean the operands.
	uint8_t optype[8] = {Omitted,
						Omitted,
						Omitted,
						Omitted,
						Omitted,
						Omitted,
						Omitted,
						Omitted};
	// Get the next operation and advance the PC.
	uint8_t op = getByte(current_frame->PC++);
	// Print the operand in debug mode.
	if(verbose_Debug >= 4)
		printf("\nPC: %5u OP: %3u\n", current_frame->PC - 1, op);
	 // Extract argument types based on the opcode.
	if(op < 128) {
		optype[0] = ((op >> 6 & 1)+1);
		optype[1] = ((op >> 5 & 1)+1);
	} else if(op < 192 && (op != 190)) {
		optype[0] = (op >> 4 & 3);
	} else {
		if(op == 190)
			extop = getByte(current_frame->PC++);
		int8_t args[2] = {0, 255};
		args[0] = getByte(current_frame->PC++);
		if(op == 236 || op == 260) {
			args[1] = getByte(current_frame->PC++);
		}
		optype[0] = args[0] >> 6 & 3;
		optype[1] = args[0] >> 4 & 3;
		optype[2] = args[0] >> 2 & 3;
		optype[3] = args[0] & 3;
		optype[4] = args[1] >> 6 & 3;
		optype[5] = args[1] >> 4 & 3;
		optype[6] = args[1] >> 2 & 3;
		optype[7] = args[1] & 3;
	}

	// Find the number of operands that have been extracted, then
	// populate them depending on their type. Print them if in debug mode.
	current_frame->nargs = 8;
	for(int i = 0; i < 8; i++) {
		switch(optype[i]) {
			case Omitted:
				if(current_frame->nargs > i)
					current_frame->nargs = i;
				operand[i] = 0;
				break;
			case LargeConstant:
				operand[i] = getWord(current_frame->PC);
				current_frame->PC += 2;
				if(verbose_Debug >= 4)
					printf("Large: %u\n", operand[i]);
				break;
			case SmallConstant:
				operand[i] = getByte(current_frame->PC++);
				if(verbose_Debug >= 4)
					printf("Small: %u\n", operand[i]);
				break;
			case Variable: {
				uint8_t var = getByte(current_frame->PC++);
				operand[i] = getZVar(var);
				if(verbose_Debug >= 4)
					printf("Var %u: %u\n", var, operand[i]);
				break; }
		}
	}
	// Execute the operation.
	callop[op]();
}
