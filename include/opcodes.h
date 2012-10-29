#ifndef OPCODES_H
#define OPCODES_H
#include <time.h>

// Signed 16-bit addition.
void op_add() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	zStore((uint16_t)(num1 + num2)&0xFFFF);
}

// Bitwise and.
void op_and() {
	zStore(Operand[0]&Operand[1]);
}

// Arithmetic shift
void op_art_shift() {
	int16_t num = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	if(num2 >= 0)
		num = num<<num2;
	else
		num = num>>(num2*(0-1));
	zStore(num);
}


// Call a routine and store the result.
void op_ret();
void op_call() {
	pushZFrame();
	CurrentZFrame->PC = exPadAdr(Operand[0]);
	if(CurrentZFrame->PC > 0xFFFFFFF) {
		fputs("Invalid routine address.\n",stderr);
		exit(1);
	}
	uint8_t lclsz = getByte(CurrentZFrame->PC++);
	CurrentZFrame->locals = calloc(sizeof(uint16_t),lclsz+1);
	CurrentZFrame->locals[0] = lclsz;
	if(getZRev() < 4)
		for(int i = 1; i < CurrentZFrame->locals[0] + 1; i++){
			CurrentZFrame->locals[i] = getWord(CurrentZFrame->PC);
			CurrentZFrame->PC += 2;
		}
	for(int i = 1; i < CurrentZFrame->old_frame->nargs;i++) {
		if(lclsz <= i)
			CurrentZFrame->locals[i] = Operand[i];
	}
	if(Operand[0] == 0) {
		op_ret();
	}
}

// Same as op_call, but throws away the result.
void op_call_throw() {
	CurrentZFrame->retvar = 0;
	op_call();
}

// Return the current number of stack frames.
void op_catch() {
	zStore(zFrameNumber(CurrentZFrame));
}

// Branch if a given number of arguments have been provided.
void op_check_arg_count() {
	zBranch(Operand[0] - 1 <= CurrentZFrame->old_frame->nargs);
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
	fputs("\nFATAL: tried to execute nonexistant opcode.\n",stderr);
	exit(1);
}

// Get the child of an object.
void op_get_child() {
	uint16_t adr = 0;
	if(Operand[0])
		adr = getChild(Operand[0]);
	printf("Child is: %u\n", adr);
	uint16_t s = getPropertyTableAdr(adr);
	s++;
	char* name = zCharsToZSCII(getZChars(s));
	zPrint(name);
	free(name);
	s = getPropertyTableAdr(Operand[0]);
	s++;
	name = zCharsToZSCII(getZChars(s));
	zPrint(name);
	free(name);
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
	if(Operand[0]+Operand[1] > 0xffff) {
		printf("Error trying to loadb from high memory.\n",stderr);
		exit(1);
	}
	zStore(getByte(Operand[0]+Operand[1]));
}

// Get a word from memory and store it.
void op_loadw() {
	if(Operand[0]+2*Operand[1] > 0xffff) {
		printf("Error trying to loadw from high memory.\n",stderr);
		exit(1);
	}
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

// Pop from the current local stack.
void op_pull() {
	setZVar(Operand[0],popZStack());
}

// Push to the current local stack.
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
	if(VerboseDebug >= 4)
		printf("Random number is: %u\n", state);
	if(Operand[0] > 0) {
		if(VerboseDebug >= 4)
			printf("Returning: %u\n",state%Operand[0]);
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
	if(CurrentZFrame->retvar == 1)
		setZVar(getByte(CurrentZFrame->PC++), Operand[0]);
	CurrentZFrame->retvar = 1;
}

// Pop from the stack and return that value.
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

// Throw away some stack frames, until the desired number is reached.
void op_throw() {
	if(Operand[1] > zFrameNumber(CurrentZFrame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(Operand[1] < zFrameNumber(CurrentZFrame))
		popZFrame();
	op_ret();
}

#endif /* OPCODES_H */
