#ifndef OPCODES_H
#define OPCODES_H
// Signed 16-bit addition.
void op_add() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	store((uint16_t)(num1 + num2)&0xFFFF);
}

// Bitwise and.
void op_and() {
	store(operand[0]&operand[1]);
}

// Arithmatic shift
void op_art_shift() {
	int16_t num = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 >= 0)
		num = num<<num2;
	else
		num = num>>(num2*(0-1));
	store(num);
}


// Call a routine and store the result.
void op_ret();
void op_call() {
	pushframe();
	current_frame->PC = exPAdr(operand[0]);
	uint8_t lclsz = getbyte(current_frame->PC++);
	current_frame->locals = calloc(sizeof(uint16_t),lclsz+1);
	current_frame->locals[0] = lclsz;
	if(Z_REV < 4)
		for(int i = 1; i < current_frame->locals[0] + 1; i++){
			current_frame->locals[i] = getword(current_frame->PC);
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

// Return current stack frame pointer.
void op_catch() {
	store(framenum(current_frame));
}

// Branch if a given number of arguemnts have been provided.
void op_check_arg_count() {
	branch(operand[0] - 1 <= current_frame->old_frame->nargs);
}

// Tell the program we cant do unicode.
void op_check_unicode() {
	store(0);
}

// Make object not have an attribute
void op_clear_attr() {
	setobjflag(operand[0], operand[1], 0);
}

// Decrement a variable.
void op_dec() {
	setvar(operand[0],getvar(operand[0]) - 1);
}

// Decrement a variable and branch if its greater than a value.
void op_dec_chk() {
	setvar(operand[0],getvar(operand[0]) - 1);
	branch(getvar(operand[0]) < operand[1]);
}

// Signed division.
void op_div() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 == 0) {
		fputs("Divide by zero error.\n", stderr);
		exit(1);
	}
	store((uint16_t)(num1 / num2)&0xFFFF);
}

// Woops! something shouldn't have happened!
void op_errnop() {
	fputs("Error, tried to execute nonexistant opcode.\n",stderr);
	exit(1);
}

// Get the child of an object.
void op_get_child() {
	store(getchild(operand[0]));
	branch(getchild(operand[0]));
}

// Get the parent of an object.
void op_get_parent() {
	store(getparent(operand[0]));
}

// Get a property of an object.
void op_get_prop() {
	uint16_t adr = getpropadr(operand[0],operand[1]);
	if(adr != 0) {
		unsigned int mode = getbyte(adr++);
		store(mode == 1 ? getbyte(adr) : getword(adr));
	} else {
		store(getword(getword(0x0a) + (2*operand[1])));
	}
}

void op_get_prop_addr() {
	uint16_t adr = getpropadr(operand[0],operand[1]);
	if(adr) {
		adr++;
		store(adr);
	} else {
		store(0);
	}
}

void op_get_sibling() {
	store(getsibling(operand[0]));
	branch(getsibling(operand[0]));
}

void op_inc() {
	setvar(operand[0],getvar(operand[0]) + 1);
}

void op_inc_chk() {
	int16_t val;
	val = getvar(operand[0]);
	setvar(operand[0],++val);
	branch(val > operand[1]);
}

void op_remove_obj();
void op_insert_obj() {
	op_remove_obj();
	uint16_t child = getchild(operand[1]);
	setsibling(operand[0], child);
	setparent(operand[0], operand[1]);
	setchild(operand[1],operand[0]);
}

void op_je() {
	branch(operand[0] == operand[1]);
}

void op_jg() {
	branch(operand[0] > operand[1]);
}

void op_jin() {
	branch(getparent(operand[0]) == operand[1]);
}

void op_jump() {
	current_frame->PC += (int16_t)operand[0] - 2;
}

void op_jl() {
	branch(operand[0] < operand[1]);
}

void op_jz() {
	branch((int16_t)operand[0] == 0);
}

void op_loadb() {
	if(operand[0]+operand[1] > 0xffff) {
		printf("Error trying to loadb from high memory.\n",stderr);
		exit(1);
	}
	store(getbyte(operand[0]+operand[1]));
}

void op_loadw() {
	if(operand[0]+2*operand[1] > 0xffff) {
		printf("Error trying to loadw from high memory.\n",stderr);
		exit(1);
	}
	store(getword(operand[0]+2*operand[1]));
}

// Arithmatic shift
void op_log_shift() {
	uint16_t num = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 >= 0)
		num = num<<num2;
	else
		num = num>>(num2*(-1));
	store(num);
}

void op_mod() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	if(num2 == 0) {
		fputs("Divide by zero error.\n", stderr);
		exit(1);
	}
	store((uint16_t)(num1 % num2)&0xFFFF);
}

void op_mul() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	store((uint16_t)(num1 * num2)&0xFFFF);
}

void op_nop() {
}

void op_new_line() {
	print("\n");
}

void op_or() {
	store(operand[0] | operand[1]);
}

void op_print() {
	char* str = getstring();
	print(str);
	free(str);
}

void op_print_char() {
	printf("%c",operand[0]);
}

void op_print_num() {
	printf("%i",operand[0]);
}

void op_print_obj() {
	uint16_t adr = getproptableadr(operand[0]);
	adr++;
	char* name = tozscii(getzchar(adr));
	print(name);
	free(name);
}

void op_pull() {
	setvar(operand[0],pop());
}
void op_push() {
	push(operand[0]);
}

void op_put_prop() {
	uint16_t adr = getpropadr(operand[0],operand[1]);
	unsigned int mode = getbyte(adr++);
	mode == 1 ? setbyte(adr,operand[2]) : setword(adr, operand[2]);
}

void op_read() {
	readstr(0);
}

void op_remove_obj() {
	uint16_t parent = getparent(operand[0]);
	if(parent != 0) {
		if(getchild(parent) == operand[0]) {
			setchild(parent, getsibling(operand[0]));
		} else {
			uint16_t last = getchild(parent);
			while(getsibling(last) != operand[0])
				last = getsibling(last);
			setsibling(last, getsibling(operand[0]));
		}
	}
	setparent(operand[0], 0);
	setsibling(operand[0], 0);
}
void op_ret() {
	popframe();
	if(current_frame->retvar == 1)
		setvar(getbyte(current_frame->PC++), operand[0]);
	current_frame->retvar = 1;
}

void op_ret_popped() {
	operand[0] = pop();
	op_ret();
}

void op_rfalse() {
	operand[0] = 0;
	op_ret();
}

void op_rtrue() {
	operand[0] = 1;
	op_ret();
}

void op_set_attr() {
	setobjflag(operand[0], operand[1], 1);
}

void op_store() {
	setvar(operand[0],operand[1]);
}

void op_storeb() {
	setbyte(operand[0]+operand[1], operand[2]);
}

void op_storew() {
	setword(operand[0]+2*operand[1], operand[2]);
}

void op_sub() {
	int16_t num1 = (int16_t)operand[0];
	int16_t num2 = (int16_t)operand[1];
	store((uint16_t)(num1 - num2)&0xFFFF);
}

void op_test() {
	branch(operand[0] & operand[1] == operand[1]);
}

void op_test_attr() {
	branch(getobjflag(operand[0], operand[1]));
}

void op_throw() {
	if(operand[1] > framenum(current_frame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(operand[1] < framenum(current_frame))
		popframe();
	op_ret();
}
#endif
