#ifndef OPCODES_H
#define OPCODES_H

// Signed 16-bit addition.
void op_add() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	zStore((uint16_t)(num1 + num2)&0xFFFF);
}

// Bitwise and.
void op_and() {
	zStore(operand[0]&operand[1]);
}

// Arithmetic shift
void op_art_shift() {
	int16_t num = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
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
	current_frame->PC = exPadAdr(operand[0]);
	uint8_t lclsz = getByte(current_frame->PC++);
	current_frame->locals = calloc(sizeof(uint16_t),lclsz+1);
	current_frame->locals[0] = lclsz;
	if(getZRev() < 4)
		for(int i = 1; i < current_frame->locals[0] + 1; i++){
			current_frame->locals[i] = getWord(current_frame->PC);
			current_frame->PC += 2;
		}
	for(int i = 1; i < current_frame->old_frame->nargs;i++) {
		if(lclsz <= i)
			current_frame->locals[i] = operand[i];
	}
	if(operand[0] == 0) {
		op_ret();
	}
}

// Same as op_call, but throws away the result.
void op_call_throw() {
	current_frame->retvar = 0;
	op_call();
}

// Return the current number of stack frames.
void op_catch() {
	zStore(zFrameNumber(current_frame));
}

// Branch if a given number of arguments have been provided.
void op_check_arg_count() {
	zBranch(operand[0] - 1 <= current_frame->old_frame->nargs);
}

// Tell the program we can't do unicode.
void op_check_unicode() {
	zStore(0);
}

// Make object not have an attribute
void op_clear_attr() {
	setObjectFlagValue(operand[0], operand[1], 0);
}

// Decrement a variable.
void op_dec() {
	setZVar(operand[0],getZVar(operand[0]) - 1);
}

// Decrement a variable and branch if its greater than a value.
void op_dec_chk() {
	setZVar(operand[0],getZVar(operand[0]) - 1);
	zBranch(getZVar(operand[0]) < operand[1]);
}

// Signed division.
void op_div() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 == 0) {
		fputs("Divide by zero error.\n", stderr);
		exit(1);
	}
	zStore((uint16_t)(num1 / num2)&0xFFFF);
}

// Woops! something shouldn't have happened!
void op_errnop() {
	fputs("Error, tried to execute nonexistant opcode.\n",stderr);
	exit(1);
}

// Get the child of an object.
void op_get_child() {
	zStore(getChild(operand[0]));
	zBranch(getChild(operand[0]));
}

// Get the parent of an object.
void op_get_parent() {
	zStore(getParent(operand[0]));
}

// Get a property of an object.
void op_get_prop() {
	uint16_t adr = getPropertyAdr(operand[0],operand[1]);
	if(adr != 0) {
		unsigned int mode = getByte(adr++);
		zStore(mode == 1 ? getByte(adr) : getWord(adr));
	} else {
		zStore(getWord(getWord(0x0a) + (2*operand[1])));
	}
}

// Get the property address of a property.
void op_get_prop_addr() {
	uint16_t adr = getPropertyAdr(operand[0],operand[1]);
	if(adr) {
		adr++;
		zStore(adr);
	} else {
		zStore(0);
	}
}

// Get the sibling of an object and store it.
void op_get_sibling() {
	zStore(getSibling(operand[0]));
	zBranch(getSibling(operand[0]));
}

// Increment a variable.
void op_inc() {
	setZVar(operand[0],getZVar(operand[0]) + 1);
}

// Increment a variable and branch if it is greater than a value.
void op_inc_chk() {
	int16_t val;
	val = getZVar(operand[0]);
	setZVar(operand[0],++val);
	zBranch(val > operand[1]);
}

// Insert an object somewhere in the object tree.
void op_remove_obj();
void op_insert_obj() {
	op_remove_obj();
	uint16_t child = getChild(operand[1]);
	setSibling(operand[0], child);
	setParent(operand[0], operand[1]);
	setChild(operand[1],operand[0]);
}

// Branch if equal.
void op_je() {
	zBranch(operand[0] == operand[1]);
}

// Branch if greater than.
void op_jg() {
	zBranch(operand[0] > operand[1]);
}

// Branch if an object is inside another.
void op_jin() {
	zBranch(getParent(operand[0]) == operand[1]);
}

// Jump unconditionally.
void op_jump() {
	current_frame->PC += (int16_t)operand[0] - 2;
}

// Branch if less than.
void op_jl() {
	zBranch(operand[0] < operand[1]);
}

// Branch if zero.
void op_jz() {
	zBranch((int16_t)operand[0] == 0);
}

// Get a byte from memory and store it.
void op_loadb() {
	if(operand[0]+operand[1] > 0xffff) {
		printf("Error trying to loadb from high memory.\n",stderr);
		exit(1);
	}
	zStore(getByte(operand[0]+operand[1]));
}

// Get a word from memory and store it.
void op_loadw() {
	if(operand[0]+2*operand[1] > 0xffff) {
		printf("Error trying to loadw from high memory.\n",stderr);
		exit(1);
	}
	zStore(getWord(operand[0]+2*operand[1]));
}

// Log shift
void op_log_shift() {
	uint16_t num = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 >= 0)
		num = num<<num2;
	else
		num = num>>(num2*(-1));
	zStore(num);
}

// Modulus.
void op_mod() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 == 0) {
		fputs("Divide by zero error.\n", stderr);
		exit(1);
	}
	zStore((uint16_t)(num1 % num2)&0xFFFF);
}

// Multiply.
void op_mul() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
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
	zStore(operand[0] | operand[1]);
}

// Print a string stored after the operation.
void op_print() {
	char* str = zGetStringFromPC();
	zPrint(str);
	free(str);
}

// Print a z-character.
void op_print_char() {
	printf("%c",operand[0]);
}

// Print a number
void op_print_num() {
	printf("%i",operand[0]);
}

// Print an objects name.
void op_print_obj() {
	uint16_t adr = getPropertyTableAdr(operand[0]);
	adr++;
	char* name = zCharsToZSCII(getZChars(adr));
	zPrint(name);
	free(name);
}

// Print a string stored at a padded address.
void op_print_paddr() {
	char* str = zCharsToZSCII(getZChars(exPadAdr(operand[0])));
	zPrint(str);
	free(str);
}

// Pop from the current local stack.
void op_pull() {
	setZVar(operand[0],popZStack());
}

// Push to the current local stack.
void op_push() {
	pushZStack(operand[0]);
}

// Set the value of a property.
void op_put_prop() {
	uint16_t adr = getPropertyAdr(operand[0],operand[1]);
	unsigned int mode = getByte(adr++);
	mode == 1 ? setByte(adr,operand[2]) : setWord(adr, operand[2]);
}

// Read a string from the user.
void op_read() {
	readString(0);
}

// Remove an object from the object tree.
void op_remove_obj() {
	uint16_t parent = getParent(operand[0]);
	if(parent != 0) {
		if(getChild(parent) == operand[0]) {
			setChild(parent, getSibling(operand[0]));
		} else {
			uint16_t last = getChild(parent);
			while(getSibling(last) != operand[0])
				last = getSibling(last);
			setSibling(last, getSibling(operand[0]));
		}
	}
	setParent(operand[0], 0);
	setSibling(operand[0], 0);
}

// REturn from a routine, returning a value if needed.
void op_ret() {
	popZFrame();
	if(current_frame->retvar == 1)
		setZVar(getByte(current_frame->PC++), operand[0]);
	current_frame->retvar = 1;
}

// Pop from the stack and return that value.
void op_ret_popped() {
	operand[0] = popZStack();
	op_ret();
}

// Return false.
void op_rfalse() {
	operand[0] = 0;
	op_ret();
}

// Return true.
void op_rtrue() {
	operand[0] = 1;
	op_ret();
}

// Set the flag of an object to on.
void op_set_attr() {
	setObjectFlagValue(operand[0], operand[1], 1);
}

// Store a value in a variable.
void op_store() {
	setZVar(operand[0],operand[1]);
}

// Set a byte in memory.
void op_storeb() {
	setByte(operand[0]+operand[1], operand[2]);
}

// Set a word in memory.
void op_storew() {
	setWord(operand[0]+2*operand[1], operand[2]);
}

//  Subtract.
void op_sub() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	zStore((uint16_t)(num1 - num2)&0xFFFF);
}

// Test to see if a bitmask is set.
void op_test() {
	zBranch((operand[0] & operand[1]) == operand[1]);
}

// Find is a flag of an object is set to on.
void op_test_attr() {
	zBranch(getObjectFlag(operand[0], operand[1]));
}

// Throw away some stack frames, until the desired number is reached.
void op_throw() {
	if(operand[1] > zFrameNumber(current_frame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(operand[1] < zFrameNumber(current_frame))
		popZFrame();
	op_ret();
}

#endif /* OPCODES_H */
