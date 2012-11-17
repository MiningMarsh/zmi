#ifndef OPCODES_H
#define OPCODES_H
#include <time.h>
#include <stdint.h>
#include "log.h"

// Table of opcodes.
void (*CallOpCode[256])(void) = {NULL};

/*********************************
 * 2OP:20 14 add a b -> (result) *
 *************************************************************************
 * Signed 16-bit addition.                                               *
 *************************************************************************/

void opAdd() {
	// The first number. to add, casted from its unsigned form in memory.
	int16_t Number1 = (int16_t)Operand[0];
	// The second number. to add, casted from its unsigned form in memory.
	int16_t Number2 = (int16_t)Operand[1];
	// Result, 23bit to check for over/undrflows which are undefined 
	// behavior that is commonly defined as modulo 10000.
	int32_t Result = (int32_t)(Number1 + Number2);
	// Did we oer/underflow?
	if(Result < -32768 || Result > 32767) {
		// Log the warning message.
		char Message[256];
		sprintf(
			Message,
			"%s detected. This is undefined behavior.\n"
			"Operands of %i and %i with result of %i.",
			Number1 > 32767 ? "Overflow" : "Underflow",
			Number1,
			Number2,
			Result
		);
		LogMessage(MWarning, "add", Message);
	}
	// Store the result.
	zStore((uint16_t)(Number1 + Number2)%10000);
}

/*******************************
 * 2OP:9 9 and a b -> (result) *
 *************************************************************************
 * Bitwise AND.                                                          *
 *************************************************************************/

void opAnd() {
	// Store operand 1 AND operand 2.
	zStore(Operand[0]&Operand[1]);
}

/***********************************************
 * 2OP:9 9 art_shift number places -> (result) *
 *************************************************************************
 * Does an arithmetic shift of _number_ by the given number of _places_, *
 * shiftin left (i.e. increasing) , right if negative. In a right shift, *
 * the sign bit is preserved as well as being shifted on down. (The      *
 * alternative behavior is 'log_shift'.)                                 *
 *************************************************************************/

void opArtShift() {
	// Number to shift.
	int16_t Number = (int16_t)Operand[0];
	// Number of places to shift by.
	int16_t Places = (int16_t)Operand[1];

	// Shift positive or negative?
	if(Places > 0) {
		// Shift left.
		Number = Number<<Places;
	} else if(Places <) {
		// Shift right.
		for( Places; Places > 0; Places--) {
			// Get the sign bit.
			int Sign = (Number>>16)&0x1;
			Number = Number>>1;
			// Restore the sign bit as well as shifting it down.
			Number = Number|(Sign<<15)|(sign<<16);
		}
	} else {
		// Print a little warning if they shift by zero, as this
		// does nothing more than wasting cpu cycles.
		LogMessage(MWarning, "art_shift", "Shifting %i by 0. This is innefficient.\n");
	}
	// Store the result.
	zStore(Number);
}

/***********************************************************
 * VAR:224 0 1 call routine ...up to 3 args... -> (result) *
 *************************************************************************
 * The only call instruction in Version 3, Inform reads this as 'call_vs'*
 * in higher versions: it calls the _routine_ with 0, 1, 2, or 4         *
 * _arguments_ as supplied and stores the resulting return value. (When  *
 * address 0 is called as a routine, nothing happens and the return      *
 * value is false.)                                                      *
 *************************************************************************/

void opCall() {
	// If address 0 is called, we instantly return 0 and nothing happens.
	if(!Operand[0]) {
		if(CurrentZFrame->ReturnVar == 1)
			setZVar(getByte(CurrentZFrame->PC++), 0);
		CurrentZFrame->ReturnVar = 1;
		return;
	}
	// Create a new blank stack frame.
	pushZFrame();
	// Expand the padded address to get the routine location.
	CurrentZFrame->PC = exPadAdr(Operand[0]);
	// Check if it is out of memory range.
	if(CurrentZFrame->PC > 0xFFFFFFF || CurrentZFrame->PC > g_RAMSize ) {
		// Log an error message if it is.
		char Message[1024];
		sprintf(
			Message,
			"Address %u expands to %u, which is out of memory range.\n"
			"Memory size is: %u",
			Operand[0],
			CurrentZFrame->PC,
			g_RAMSize
		);
		LogMessage(MFatal, "call", Message);
		exit(1);
	}
	// Get the number of local variables the routine has.
	uint8_t NumberLocals = getByte(CurrentZFrame->PC++);
	// Allocate room for the locals.
	CurrentZFrame->Locals = calloc(sizeof(uint16_t), NumberLocals+1);
	CurrentZFrame->Locals[0] = NumberLocals;
	// Special handling for revision 3 and lower.
	if(getZRev() < 4)
		// Revision 3 andlower define default values for all routine
		// arguments. Get them and assign them here. revisions 4 and up 
		// use 0 for all default values.
		for(int I = 1; I < CurrentZFrame->Locals[0] + 1; I++) {
			CurrentZFrame->Locals[I] = getWord(CurrentZFrame->PC);
			CurrentZFrame->PC += 2;
		}
	// Pass the supplied arguments to the rutine being called
	// by putting them on the stack frame.
	for(int I = 1; I < CurrentZFrame->OldFrame->PassedArgs;I++)
		if(NumberLocals <= I)
			CurrentZFrame->Locals[I] = Operand[I];
}

/***************************************************
 * VAR:249 19 5 call_vn routine ...up to 3 args... *
 *************************************************************************
 * Like 'call', but throws away the result.                              *
 *************************************************************************/

void opCallVN () {
	// Set up metadata saying this stackframe doesn't return anything.
	CurrentZFrame->ReturnVar = 0;
	// Transfer to a standard routine call.
	opCall();
}

/***********************************
 * 0OP:185 0 5/6 catch -> (result) *
 *************************************************************************
 * Opposite to 'throw' (and occupying the same opcode that 'pop' used in *
 * Version 3 and 4. 'catch' returns the current stackframe.              *
 *************************************************************************/

void opCatch() {
	zStore(zFrameNumber(CurrentZFrame));
}

/************************************************
 * VAR:255 1F 5 check_arg_count argument-number *
 *************************************************************************
 * Opposite to 'throw' (and occupying the same opcode that 'pop' used in *
 * Version 3 and 4. 'catch' returns the current stackframe.              *
 *************************************************************************/

void opCheckArgCount() {
	zBranch(Operand[0] - 1 <= CurrentZFrame->OldFrame->PassedArgs);
}

// Tell the program we can't do unicode.
void op_check_unicode() {
	zStore(0);
}

// Make object not have an attribute
void op_clear_attr() {
	setObjectFlagValue(Operand[0], Operand[1], 0);
}

// Decrement a variable.
void op_dec() {
	setZVar(Operand[0],getZVar(Operand[0]) - 1);
}

// Decrement a variable and branch if its greater than a value.
void op_dec_chk() {
	setZVar(Operand[0],getZVar(Operand[0]) - 1);
	zBranch(getZVar(Operand[0]) < Operand[1]);
}

// Signed division.
void op_div() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	if(num2 == 0) {
		fputs("\nFATAL: Divide by zero error.\n", stderr);
		exit(1);
	}
	zStore((uint16_t)(num1 / num2)&0xFFFF);
}

// Woops! something shouldn't have happened!
void op_errnop() {
	LogMessage(MFatal, "op_err()", "Tried to execute nonexistant opcode!");
	exit(1);
}

// Get the child of an object.
void op_get_child() {
	uint16_t adr = 0;
	if(Operand[0])
		adr = getChild(Operand[0]);
	zStore(adr);
	zBranch(adr);
}

// Get the parent of an object.
void op_get_parent() {
	uint16_t adr = 0;
	if(Operand[0])
		adr = getParent(Operand[0]);
	zStore(adr);
}

// Get a property of an object.
void op_get_prop() {
	uint16_t adr = getPropertyAdr(Operand[0],Operand[1]);
	if(adr != 0) {
		unsigned int mode = getByte(adr++);
		zStore(mode == 1 ? getByte(adr) : getWord(adr));
	} else {
		zStore(getWord(getWord(0x0a) + (2*Operand[1])));
	}
}

// Get the property address of a property.
void op_get_prop_addr() {
	uint16_t adr = getPropertyAdr(Operand[0],Operand[1]);
	if(adr)
		adr++;
	zStore(adr);
}

// Get the sibling of an object and store it.
void op_get_sibling() {
	zStore(getSibling(Operand[0]));
	zBranch(getSibling(Operand[0]));
}

// Increment a variable.
void op_inc() {
	setZVar(Operand[0],getZVar(Operand[0]) + 1);
}

// Increment a variable and branch if it is greater than a value.
void op_inc_chk() {
	int16_t val;
	val = getZVar(Operand[0]);
	setZVar(Operand[0],++val);
	zBranch(val > Operand[1]);
}

// Insert an object somewhere in the object tree.
void op_remove_obj();
void op_insert_obj() {
	op_remove_obj();
	uint16_t child = getChild(Operand[1]);
	setSibling(Operand[0], child);
	setParent(Operand[0], Operand[1]);
	setChild(Operand[1],Operand[0]);
}

// Branch if equal.
void op_je() {
	zBranch(Operand[0] == Operand[1]);
}

// Branch if greater than.
void op_jg() {
	zBranch(Operand[0] > Operand[1]);
}

// Branch if an object is inside another.
void op_jin() {
	zBranch(getParent(Operand[0]) == Operand[1]);
}

// Jump unconditionally.
void op_jump() {
	CurrentZFrame->PC += (int16_t)Operand[0] - 2;
}

// Branch if less than.
void op_jl() {
	zBranch(Operand[0] < Operand[1]);
}

// Branch if zero.
void op_jz() {
	zBranch((int16_t)Operand[0] == 0);
}

// Get a byte from memory and store it.
void op_loadb() {
	zStore(getByte(Operand[0]+Operand[1]));
}

// Get a word from memory and store it.
void op_loadw() {
	zStore(getWord(Operand[0]+2*Operand[1]));
}

// Log shift
void op_log_shift() {
	uint16_t num = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	if(num2 >= 0)
		num = num<<num2;
	else
		num = num>>(num2*(-1));
	zStore(num);
}

// Modulus.
void op_mod() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	if(num2 == 0) {
		fputs("Divide by zero error.\n", stderr);
		exit(1);
	}
	zStore((uint16_t)(num1 % num2)&0xFFFF);
}

// Multiply.
void op_mul() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	zStore((uint16_t)(num1 * num2)&0xFFFF);
}

// No operation.
void op_nop() {
}


// Print a newline.
void op_new_line() {
	zPrint("\n");
}

// Logical or.
void op_or() {
	zStore(Operand[0] | Operand[1]);
}

// Print a string stored after the operation.
void op_print() {
	char* str = zGetStringFromPC();
	zPrint(str);
	free(str);
}

// Print a string stored after the operation.
void op_print_ret() {
	op_print();
	op_new_line();
	op_ret();
}

// Print a z-character.
void op_print_char() {
	printf("%c",Operand[0]);
}

// Print a number
void op_print_num() {
	printf("%i",Operand[0]);
}

// Print an objects name.
void op_print_obj() {
	uint16_t adr = getPropertyTableAdr(Operand[0]);
	adr++;
	char* name = zCharsToZSCII(getZChars(adr));
	zPrint(name);
	free(name);
}

// Print a string stored at a padded address.
void op_print_paddr() {
	char* str = zCharsToZSCII(getZChars(exPadAdr(Operand[0])));
	zPrint(str);
	free(str);
}

// Pop from the current local Stack.
void op_pull() {
	setZVar(Operand[0],popZStack());
}

// Push to the current local Stack.
void op_push() {
	pushZStack(Operand[0]);
}

// Set the value of a property.
void op_put_prop() {
	uint16_t adr = getPropertyAdr(Operand[0],Operand[1]);
	unsigned int mode = getByte(adr++);
	mode == 1 ? setByte(adr,Operand[2]) : setWord(adr, Operand[2]);
}

// Get a random number.
void op_random() {
	static uint16_t state = 0;
	if(!state)
		state = time(NULL)%0xFFFF;
	uint8_t next;
	for(int i = 0; i != 16; i++) {
		next = (state&15)^((state>>2)&13)^((state>>2)&13)^((state>>6)&10);
		state = ((state<<1)) + (next);
	}
	if(Operand[0] > 0) {
		zStore(state%Operand[0]);
	} else if(Operand[0] < 0) {
		zStore(0);
		state = Operand[0];
	} else {
		zStore(0);
		state = time(NULL)%0xFFFF;
	}
}

// Read a string from the user.
void op_read() {
	readString(0);
}

// Remove an object from the object tree.
void op_remove_obj() {
	uint16_t parent = getParent(Operand[0]);
	if(parent != 0) {
		if(getChild(parent) == Operand[0]) {
			setChild(parent, getSibling(Operand[0]));
		} else {
			uint16_t last = getChild(parent);
			while(getSibling(last) != Operand[0])
				last = getSibling(last);
			setSibling(last, getSibling(Operand[0]));
		}
	}
	setParent(Operand[0], 0);
	setSibling(Operand[0], 0);
}

// REturn from a routine, returning a value if needed.
void op_ret() {
	popZFrame();
	if(CurrentZFrame->ReturnVar == 1)
		setZVar(getByte(CurrentZFrame->PC++), Operand[0]);
	CurrentZFrame->ReturnVar = 1;
}

// Pop from the Stack and return that value.
void op_ret_popped() {
	Operand[0] = popZStack();
	op_ret();
}

// Return false.
void op_rfalse() {
	Operand[0] = 0;
	op_ret();
}

// Return true.
void op_rtrue() {
	Operand[0] = 1;
	op_ret();
}

// Set the flag of an object to on.
void op_set_attr() {
	setObjectFlagValue(Operand[0], Operand[1], 1);
}

// Store a value in a variable.
void op_store() {
	setZVar(Operand[0],Operand[1]);
}

// Set a byte in memory.
void op_storeb() {
	setByte(Operand[0]+Operand[1], Operand[2]);
}

// Set a word in memory.
void op_storew() {
	setWord(Operand[0]+2*Operand[1], Operand[2]);
}

//  Subtract.
void op_sub() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	zStore((uint16_t)(num1 - num2)&0xFFFF);
}

// Test to see if a bitmask is set.
void op_test() {
	zBranch((Operand[0] & Operand[1]) == Operand[1]);
}

// Find is a flag of an object is set to on.
void op_test_attr() {
	zBranch(getObjectFlag(Operand[0], Operand[1]));
}

// Throw away some Stack frames, until the desired number is reached.
void op_throw() {
	if(Operand[1] > zFrameNumber(CurrentZFrame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(Operand[1] < zFrameNumber(CurrentZFrame))
		popZFrame();
	op_ret();
}

void initOpCodes() {
	CallOpCode[9] = 
	CallOpCode[41] =
	CallOpCode[73] = 
	CallOpCode[105] = &opAdd;
}

#endif /* OPCODES_H */
