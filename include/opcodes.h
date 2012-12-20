#ifndef OPCODES_H
#define OPCODES_H
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "log.h"

// Table of opcodes.
void (*CallOpCode[256])(void) = {NULL};

void opRet();

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
	// Did we over/underflow?
	static bool AlreadyWarned = false;
	if(!AlreadyWarned)
		if(Result < -32768 || Result > 32767) {
			// Log the warning message.
			char Message[256];
			sprintf(
				Message,
				"%s detected. This is undefined behavior.\n"
				"Operands of %i and %i with result of %i.\n"
				"This is only reported once.",
				(char*)(Number1 > 32767 ? "Overflow" : "Underflow"),
				Number1,
				Number2,
				Result
			);
			LogMessage(MWarning, "add", Message);
			AlreadyWarned = true;
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
	} else if(Places < 0) {
		// Shift right.
		for(; Places > 0; Places--) {
			// Get the sign bit.
			int Sign = (Number>>16)&0x1;
			Number = Number>>1;
			// Restore the sign bit as well as shifting it down.
			Number = Number|(Sign<<15)|(Sign<<16);
		}
	} else {
		// Print a little warning if they shift by zero, as this
		// does nothing more than waste cpu cycles.
		static bool AlreadyReported = false;
		if(!AlreadyReported) {
			AlreadyReported = true;
			LogMessage(
				MWarning, 
				"art_shift",
				"Shifting %i by 0. This is innefficient.\n"
				"This is only reported once."
			);
		}
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
 * Version 3 and 4.) 'catch' returns the current stackframe.             *
 *************************************************************************/

void opCatch() {
	zStore(zFrameNumber(CurrentZFrame));
}

/************************************************
 * VAR:255 1F 5 check_arg_count argument-number *
 *************************************************************************
 * Branch if a given argument number (couting by 1) has been provided by *
 * the routine call to the current routine. (This allows routines in     *
 * 5 and later to distingiush between calls routine(1) and routine(1,0)  *
 * which would otherwise be impossible to tell apart.)                   *
 *************************************************************************/

void opCheckArgCount() {
	zBranch(Operand[0] - 1 <= CurrentZFrame->OldFrame->PassedArgs);
}

/******************************************************
 * EXT:12 C 5/* check_unicode char-number -> (result) *
 *************************************************************************
 * Determines whether or not the interperter can print, or recieve from  *
 * the keyboard, the given Unicode character. Bit 0 should be set if and *
 * only if the interpreter can print the character, bit 1 if and only if *
 * the interpreter can receive it from the keyboard. Bits 2 to 15 are    *
 * undefined.                                                            *
 *************************************************************************/

void opCheckUnicode() {
	// No unicode support yet.
	zStore(0);
}

/****************************************
 * 2OP:12 C clear_attr object attribute *
 *************************************************************************
 * Make object not have the attribute numbered attribute.                *
 *************************************************************************/

void opClearAttr() {
	// Set the specified flg to 0.
	setObjectFlagValue(Operand[0], Operand[1], 0);
}

/****************************
 * 1OP:134 6 dec (variable) *
 *************************************************************************
 * Decrement variable by 1. This is signed, so 0 decrements to -1.       *
 *************************************************************************/

void opDec() {
	int16_t Value = getZVar(Operand[0]);
	Value--;
	setZVar(Operand[0], (uint16_t)Value);
}

/***********************************************
 * 2OP:4 4 dec_check (variable) value ?(label) *
 *************************************************************************
 * Decrement variable, and branch if it is now less than the given       *
 * value.                                                                *
 *************************************************************************/

void opDecChk() {
	// Perform the decrement.
	opDec();

	// Check the new value;
	int16_t Variable = getZVar(Operand[0]);
	int16_t Value = Operand[1];
	zBranch(Variable < Value);
}

/*********************************
 * 2OP:23 17 div a b -> (result) *
 *************************************************************************
 * Signed 16-bit division. Division by zero should halt the interpreter  *
 * with a suitable error message.                                        *
 *************************************************************************/
void opDiv() {
	int16_t Operator = (int16_t)Operand[0];
	int16_t Dividend = (int16_t)Operand[1];
	if(Dividend == 0) {
		LogMessage(MFatal, "div", "Divide by zero.");
		exit(1);
	}
	zStore((uint16_t)(Operator / Dividend)&0xFFFF);
}

/*********
 * DUMMY *
 *************************************************************************
 * A dummy opcode that should crash the interpreter. This gets executed  *
 * when a bad opcode is detected.                                        *
 *************************************************************************/

void opNonexistant() {
	LogMessage(MFatal, "opNonexistant()", "Tried to execute nonexistant opcode!");
	exit(1);
}

/***************************************************
 * 1OP:130 2 get_child object -> (result) ?(label) *
 *************************************************************************
 * Get object contained in given object, branching if this exists, i.e.  *
 * is not nothing (i.e., is not 0).                                      *
 *************************************************************************/

void opGetChild() {
	if(!Operand[0]) {
		LogMessage(MFatal, "get_child", "Tried to get object in object 0.");
		exit(1);
	}
	// Get the address of the child.
	uint16_t Address = getChild(Operand[0]);
	zStore(Address);
	zBranch(Address);
}

/*******************************************
 * 1OP:131 3 get_parent object -> (result) *
 *************************************************************************
 * Get parent object (note this has no "banch if exists" clause).        *
 *************************************************************************/

void opGetParent() {
	if(!Operand[0]) {
		LogMessage(MFatal, "get_parent", "Tried to get object in object 0.");
		exit(1);
	}
	uint16_t Address = getParent(Operand[0]);
	zStore(Address);
}

/**************************************************
 * 2OP:17 11 get_prop object property -> (result) *
 *************************************************************************
 * Read property from object (resulting in the default value if it had   *
 * no such declared property). If the property has length 1, the value   *
 * only that byte. If it has length of 2, the first two bytes of that    *
 * property is taken as a word value. It is illegal for the opcode to be *
 * if the property has length greater then 2, and the result is          *
 * unspecified.                                                          *
 *************************************************************************/

// Get a property of an object.
void opGetProp() {
	// Get the property address.
	uint16_t Address = getPropertyAdr(Operand[0],Operand[1]);
	if(Address != 0) {
		// If it existed, find its size.
		unsigned int Size = getByte(Address++);
		if(Size == 1) {
			zStore(getByte(Address));
		} else if(Size == 2 {
			zStore(getWord(Address));
		} else {
			LogMessage(MFatal, "get_prop", "Property size is greater then 2.");
			exit(1);
		}
	} else {
		zStore(getWord(getWord(0x0a) + (2*Operand[1])));
	}
}

/*******************************************************
 * 2OP:18 12 get_prop_addr object property -> (result) *
 *************************************************************************
 * Get the byte address (in dynamic memory) of the property data for the *
 * given object's property. This must return 0 if the property doesn't   *
 * exist.                                                                *
 *************************************************************************/

void opGetPropAddr() {
	uint16_t Address = getPropertyAdr(Operand[0], Operand[1]);
	if(Address)
		Address++;
	zStore(Address);
}

/*****************************************************
 * 1OP:129 1 get_sibling object -> (result) ?(label) *
 *************************************************************************
 * Get next object in tree, branching if this exists, i.e. is not 0.     *
 *************************************************************************/

 void opGetSibling() {
	 if(!Operand[0]) {
		LogMessage(MFatal, "get_sibling", "Tried to get sibling of object 0.");
		exit(1);
	}
	zStore(getSibling(Operand[0]));
	zBranch(getSibling(Operand[0]));
}

/****************************
 * 1OP:133 5 inc (variable) *
 *************************************************************************
 * Increment variable by 1. (This is signed, so -1 increments to 0.)     *
 *************************************************************************/

void opInc() {
	int16_t Value = getZVar(Operand[0]);
	Value++;
	setZVar(Operand[0], (uint16_t)Value);
}

/*********************************************
 * 2OP:5 5 inc_chk (variable) value ?(label) *
 *************************************************************************
 * Increment variable, and branch if now greater than value.             *
 *************************************************************************/
 
void opIncChk() {
	// Perform the increment.
	opInc();

	// Check the new value;
	int16_t Variable = getZVar(Operand[0]);
	int16_t Value = Operand[1];
	zBranch(Variable > Value);
}

/******************************************
 * 2OP:14 E insert_obj object destination *
 *************************************************************************
 * Moves object O to become the first child of the destination object D. *
 * (Thus, after the operation the child of D is O, and the sibling of O  *
 * is whatever was previously the child of D.) All children of O move    *
 * with it. (Initially O can be at any point in the object tree; it may  *
 * legally have parent zero.)                                            *
 *************************************************************************/
 
void opRemoveObj();
void opInsertObj() {
	opRemoveObj();
	uint16_t Child = getChild(Operand[1]);
	setSibling(Operand[0], Child);
	setParent(Operand[0], Operand[1]);
	setChild(Operand[1],Operand[0]);
}

/***************************
 * 2OP:1 1 je a b ?(label) *
 *************************************************************************
 * Jump if a is equal to any of the subsequent operands. (Thus @je a     *
 * never jumps and @je a b jumps if a = b.)                              *
 *************************************************************************/

void opJe() {
	bool DoJump = false;
	for(int I = 1; I < 8; I++) {
		if((OperandType[I] != Omitted) && (Operand[0] == Operand[I]))
			DoJump = true;
	}
	zBranch(DoJump);
}

/***************************
 * 2OP:3 3 jg a b ?(label) *
 *************************************************************************
 * Jump if a > b (using a signed 16-bit comparison).                     *
 *************************************************************************/

void opJg() {
	int16_t A = Operand[0];
	int16_t B = Operand[1];
	zBranch(A > B);
}

/**********************************
 * 2OP:6 6 jin obj1 obj2 ?(label) *
 *************************************************************************
 * Jump if object a is a direct child of b, i.e., if parent of a is b.   *
 *************************************************************************/

void opJin() {
	zBranch(getParent(Operand[0]) == Operand[1]);
}

/***************************
 * 2OP:2 2 jl a b ?(label) *
 *************************************************************************
 * Jump if a < b (using a signed 16-bit comparison).                     *
 * ***********************************************************************/

void opJl() {
	zBranch(Operand[0] < Operand[1]);
}

/***************************
 * 1OP:140 C jump ?(label) *
 *************************************************************************
 * Jump (unconditionally) to the given label. (This is not a branch      *
 * instruction and the operand is a 2-byte signed offset to apply to the *
 * program counter.) It is legal for this to jump into a different       *
 * routine (which should not change the routine call state), although it *
 * is considered bad practice to do so and the Txd disassembler is       *
 * confused by it.                                                       *
 *************************************************************************/

void opJump() {
	CurrentZFrame->PC += (int16_t)Operand[0] - 2;
}

/***************************
 * 1OP:128 0 jz a ?(label) *
 *************************************************************************
 * Jump if a = 0.                                                        *
 *************************************************************************/

void opJz() {
	zBranch(!Operand[0]);
}

/************************************************
 * 2OP:16 10 loadb array byte-index -> (result) *
 *************************************************************************
 * Stores array->byte-index (i.e., the byte at address array+byte-index, *
 *  which must lie in static or dynamic memory).                         *
 *************************************************************************/

void opLoadb() {
	zStore(getByte(Operand[0]+Operand[1]));
}

/***********************************************
 * 2OP:15 F loadw array word-index -> (result) *
 *************************************************************************
 * Stores array-->word-index (i.e., the word at address                  *
 * array+2*word-index, which must lie in static or dynamic memory).      *
 *************************************************************************/

void opLoadw() {
	zStore(getWord(Operand[0]+2*Operand[1]));
}

/*************************************************
 * EXT:2 2 5 log_shift number places -> (result) *
 *************************************************************************
 * Does a logical shift of number by the given number of places,         *
 * shifting left (i.e. increasing) if places is positive, right if       *
 * negative. In a right shift, the sign is zeroed instead of being       *
 * shifted on. (See also art_shift.)                                     *
 *************************************************************************/

void opLogShift() {
	uint16_t Number = (int16_t)Operand[0];
	int16_t Places = (int16_t)Operand[1];
	if(Places >= 0)
		Number = Number << Places;
	else
		Number = Number >> (Places*(-1));
	zStore(Number);
}

/*********************************
 * 2OP:24 18 mod a b -> (result) *
 *************************************************************************
 * Remainder after signed 16-bit division. Division by zero should halt  *
 * the interpreter with a suit-able error message.                       *
 *************************************************************************/

void opMod() {
	int16_t Base = (int16_t)Operand[0];
	int16_t Dividend = (int16_t)Operand[1];
	if(Dividend == 0) {
		LogMessage(MFatal, "mod", "Modulus by zero.");
		exit(1);
	}
	zStore((uint16_t)(Base % Dividend)&0xFFFF);
}

/*********************************
 * 2OP:22 16 mul a b -> (result) *
 *************************************************************************
 * Signed 16-bit multiplication.                                         *
 *************************************************************************/
 
void opMul() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	zStore((uint16_t)(num1 * num2)&0xFFFF);
}

/**********************
 * 0OP:187 B new_line *
 *************************************************************************
 * Print carriage return.                                                *
 *************************************************************************/

// Print a newline.
void opNewLine() {
	zPrint("\n");
}

/*********************
 * 0OP:180 4 1/- nop *
 *************************************************************************
 * Probably the official "no operation" instruction, which,              *
 * appropriately, was never operated (in any of the Infocom datafiles):  *
 * it may once have been a breakpoint.                                   *
 *************************************************************************/
 
void opNop() {
	// This is "probably" standard compliant.
	if(Dividend == 0) {
		LogMessage(MWarning, "nop", 
			"Nop wastes both cpu cycles, and is\n"
			"not fully defined in the standard, and is therefore undefined"
			"behavior. Don't use it."
		);
		exit(1);
	}
}

/******************************
 * 2OP:8 8 or a b -> (result) *
 *************************************************************************
 * Bitwise OR.                                                           *
 *************************************************************************/

void opOr() {
	zStore(Operand[0] | Operand[1]);
}

/*********************************
 * 0OP:191 F 5/- piracy ?(label) *
 *************************************************************************
 * Branches if the game disc is believed to be genuine by the            *
 * interpreter (which is assumed to have some arcane way of finding      *
 * out). Interpreters are asked to be gullible and to unconditionally    *
 * branch.                                                               *
 *************************************************************************/

void opPiracy() {
	zBranch(true);
}

/*******************
 * 0OP:178 2 print *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string.                          *
 *************************************************************************/

void opPrint() {
	// The string on this operation is stored on teh byte now pointed to
	// by the program counter.
	char* String = zGetStringFromPC();
	zPrint(String);
	
	// zPrint does not autofree.
	free(String);
}

/**********************************************
 * VAR:229 5 print_char output-character-code *
 *************************************************************************
 * Print a ZSCII character. The operand must be a character code defined *
 * in ZSCII for output (see S 3). In particular, it must certainly not   *
 * be negative or larger than 1023.                                      *
 *************************************************************************/ 

void opPrintChar() {
	// TODO: Make this operation standard compliant.
	printf("%c",Operand[0]);
}

/*****************************
 * VAR:230 6 print_num value *
 *************************************************************************
 * Print (signed) number in decimal.                                     *
 *************************************************************************/

void opPrintNum() {
	// TODO: Fix zPrint so that this can use that instead of printf.
	printf("%i",Operand[0]);
}

/******************************
 * 1OP:138 A print_obj object *
 *************************************************************************
 * Print short name of object (the Z-encoded string in the object        * 
 * header, not a property). If the object number is invalid, the         *
 * interpreter should halt with a suitable error message.                *
 *************************************************************************/

void opPrintObj() {
	// TODO: Implement %s in zprint to fix this potential code injecction
	// exploit.
	uint16_t PropertyTableAddress = getPropertyTableAdr(Operand[0]);
	 PropertyTableAddress++;
	char* ObjectName = zCharsToZSCII(getZChars( PropertyTableAddress));
	zPrint(ObjectName);
	free(ObjectName);
}

/**************************************************
 * 1OP:141 D print_paddr packed-address-of-string *
 *************************************************************************
 * Print the (Z-encoded) string at the given packed address in high      *
 * memory.                                                               *
 *************************************************************************/

void opPrintPaddr() {
	char* String = zCharsToZSCII(getZChars(exPadAdr(Operand[0])));
	zPrint(String);
	free(String);
}

/***********************
 * 0OP:179 3 print_ret *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string, then print a new-line    *
 * and then return true (i.e., 1).                                       *
 *************************************************************************/

void opPrint();
void opNewLine();
void opRTrue();

void opPrintRet() {
	opPrint();
	opNewLine();
	opRTrue();
}

/*******************************
 * VAR:233 9 1 pull (variable) *
 * 6 pull stack -> (result)    *
 *************************************************************************
 * Pulls value off a stack. (If the stack underflows, the interpreter    *
 * should halt with a suitable error message.) In Version 6, the stack   *
 * in question may be specified as a user one: otherwise it is the game  *
 * stack.                                                                *
 *************************************************************************/
 
void opPull() {
	setZVar(Operand[0],popZStack());
}

// Push to the current local Stack.
void opPush() {
	pushZStack(Operand[0]);
}

// Set the value of a property.
void opPutProp() {
	uint16_t adr = getPropertyAdr(Operand[0],Operand[1]);
	unsigned int mode = getByte(adr++);
	mode == 1 ? setByte(adr,Operand[2]) : setWord(adr, Operand[2]);
}

// Get a random number.
void opRandom() {
	// This state varibale represents the current value of the LFSR. 
	// Since in normal operation, a LFSR will never reach state 0, we
	// can assume a value of 0 means we have not yet initilized the LFSR.
	static uint16_t State = 0;
	// Set the inital random value to the current clock.
	if(!State)
		State = time(NULL)%0xFFFF;
	uint8_t Next; // Holds the next value of the LFSR.
	for(int I = 0; I != 16; I++) {
		Next = (State&15)^((State>>2)&13)^((State>>2)&13)^((State>>6)&10);
		State = ((State<<1)) + (Next);
	}
	if(Operand[0] > 0) {
		zStore(State%Operand[0]);
	} else if(Operand[0] < 0) {
		zStore(0);
		State = Operand[0];
	} else {
		zStore(0);
		State = time(NULL)%0xFFFF;
	}
}

// Read a string from the user.
void opRead() {
	readString(0);
}

// Remove an object from the object tree.
void opRemoveObj() {
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

// Return from a routine, returning a value if needed.
void opRet() {
	popZFrame();
	if(CurrentZFrame->ReturnVar == 1)
		setZVar(getByte(CurrentZFrame->PC++), Operand[0]);
	CurrentZFrame->ReturnVar = 1;
}

// Pop from the Stack and return that value.
void opRetPopped() {
	Operand[0] = popZStack();
	opRet();
}

// Return false.
void opRfalse() {
	Operand[0] = 0;
	opRet();
}

// Return true.
void opRtrue() {
	Operand[0] = 1;
	opRet();
}

// Set the flag of an object to on.
void opSetAttr() {
	setObjectFlagValue(Operand[0], Operand[1], 1);
}

// Store a value in a variable.
void opStore() {
	setZVar(Operand[0],Operand[1]);
}

// Set a byte in memory.
void opStoreb() {
	setByte(Operand[0]+Operand[1], Operand[2]);
}

// Set a word in memory.
void opStorew() {
	setWord(Operand[0]+2*Operand[1], Operand[2]);
}

// Subtract.
void opSub() {
	int16_t num1 = (int16_t)Operand[0];
	int16_t num2 = (int16_t)Operand[1];
	zStore((uint16_t)(num1 - num2)&0xFFFF);
}

// Test to see if a bitmask is set.
void opTest() {
	zBranch((Operand[0] & Operand[1]) == Operand[1]);
}

// Find is a flag of an object is set to on.
void opTestAttr() {
	zBranch(getObjectFlag(Operand[0], Operand[1]));
}

// Throw away some Stack frames, until the desired number is reached.
void opThrow() {
	if(Operand[1] > zFrameNumber(CurrentZFrame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(Operand[1] < zFrameNumber(CurrentZFrame))
		popZFrame();
	opRet();
}

void initOpCodes() {
	for(int I = 0; I < 256; I++) {
		CallOpCode[I] = &opNonexistant;
	}
	for(int I = 0; I <= 32; I++) {
		CallOpCode[1+I] = opJe;
		CallOpCode[2+I] = opJl;
		CallOpCode[3+I] = opJg;
		CallOpCode[4+I] = opDecChk;
		CallOpCode[5+I] = opIncChk;
		CallOpCode[6+I] = opJin;
		CallOpCode[7+I] = opTest;
		CallOpCode[8+I] = opOr;
		CallOpCode[9+I] = opAnd;
		CallOpCode[10+I] = opTestAttr;
		CallOpCode[11+I] = opSetAttr;
		CallOpCode[12+I] = opClearAttr;
		CallOpCode[13+I] = opStore;
		CallOpCode[14+I] = opInsertObj;
		CallOpCode[15+I] = opLoadw;
		CallOpCode[16+I] = opLoadb;
		CallOpCode[17+I] = opGetProp;
		CallOpCode[18+I] = opGetPropAddr;
		CallOpCode[19+I] = opGetNextProp;
		CallOpCode[20+I] = opAdd;
		CallOpCode[21+I] = opSub;
		CallOpCode[22+I] = opMul;
		CallOpCode[23+I] = opDiv;
		CallOpCode[24+I] = opMod;
		CallOpCode[25+I] = opCall;
		CallOpCode[26+I] = opCall;
		CallOpCode[28+I] = opThrow;

	}
	CallOpCode[224] = &opCall;
}

#endif /* OPCODES_H */
