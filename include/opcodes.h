#ifndef OPCODES_H
#define OPCODES_H
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "log.h"

// Table of opcodes.
void (*CallOpCode[256])(void) = {NULL};

/* --------------------------------------------------------------------- */

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

/********************************************************
 * EXT:12 C 5 / * check_unicode char-number -> (result) *
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
		} else if(Size == 2) {
			zStore(getWord(Address));
		} else {
			LogMessage(MFatal, "get_prop", "Property size is greater then 2.");
			//fexit(1);
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
	zBranch(Operand[0] == Operand[1]);
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
	LogMessage(MWarning, "nop", 
		"Nop wastes both cpu cycles, and is\n"
		"not fully defined in the standard, and is therefore undefined\n"
		"behavior. Don't use it."
		);
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
void opRtrue();

void opPrintRet() {
	opPrint();
	opNewLine();
	opRtrue();
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

/************************
 * VAR:232 8 push value *
 *************************************************************************
 * Pushes value onto the game stack.                                     *
 *************************************************************************/

void opPush() {
	pushZStack(Operand[0]);
}

/********************************************
 * VAR:227 3 put_prop object property value *
 *************************************************************************
 * Writes the given value to the given property of the given object. If  *
 * the property does not exist for that object, the interpreter should   *
 * halt with a suitable error message. If the property length is 1, then *
 * the interpreter should store only the least significant byte of the   *
 * value. (For instance, storing -1 into a 1-byte property results in    *
 * the property value 255.) As with get_prop the property length must    *
 * not be more than 2: if it is, the behaviour of the opcode is          *
 * undefined.                                                            *
 *************************************************************************/

void opPutProp() {
	uint16_t Address = getPropertyAdr(Operand[0],Operand[1]);
	unsigned int Size = getByte(Address++);
	if(Size == 1) {
		setByte(Address,Operand[2]);
	} else if(Size == 2) {
		setWord(Address, Operand[2]);
	} else {
		LogMessage(MFatal, "put_prop", "Property size is greater then 2.");
		//exit(1);
	}
}

/**************************************
 * VAR:231 7 random range -> (result) *
 *************************************************************************
 * If range is positive, returns a uniformly random number between 1 and *
 * range. If range is negative, the random number generator is seeded to *
 * that value and the return value is 0. Most interpreters consider      *
 * giving 0 as range illegal (because they attempt a division with       *
 * remainder by the range), but correct behaviour is to reseed the       *
 * generator in as random a way as the interpreter can(e.g. by using the *
 * time in milliseconds). (Some version 3 games, such as 'Enchanter'     *
 * release 29, had a debugging verb #random such that typing, say,       *
 * #random 14 caused a call of random with -14.)                         *
 *************************************************************************/

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

/*********************************************************
 * VAR:228 4 1 sread text parse                          *
 *           4 sread text parse time routine             *
 *           5 aread text parse time routine -> (result) *
 *************************************************************************
 * (Note that Inform internally names the read opcode as aread in        *
 * Versions 5 and later and sread in Versions 3 and 4.)                  *
 * This opcode reads a whole command from the keyboard (no prompt is     *
 * automatically displayed). It is legal for this to be called with the  *
 * cursor at any position on any window. In Versions 1 to 3, the status  *
 * line is automatically redisplayed first. A sequence of characters is  *
 * read in from the current input stream until a carriage return (or, in *
 * Versions 5 and later, any terminating character) is found. In         *
 * Versions 1 to 4, byte 0 of the text-buffer should initially contain   *
 * the maximum number of letters which can be typed, minus 1             *
 * (the interpreter should not accept more than this). The text typed is *
 * reduced to lower case (so that it can tidily be printed back by the   *
 * program if need be) and stored in bytes 1 onward, with a zero         *
 * terminator (but without any other terminator, such as a carriage      *
 * return code). (This means that if byte 0 contains n then the buffer   *
 * must contain n+1 bytes, which makes it a string array of length n in  *
 * Inform terminology.) In Versions 5 and later, byte 0 of the           *
 * text-buffer should initially contain the maximum number of letters    *
 * which can be typed (the interpreter should not accept more than       *
 * this). The interpreter stores the number of characters actually typed *
 * in byte 1 (not counting the terminating character), and the           *
 * characters themselves in bytes 2 onward (not storing the terminating  *
 * character). (Some interpreters wrongly add a zero byte after the text *
 * anyway, so it is wise for the buffer to contain at least n+3 bytes.)  *
 *                                                                       *
 * Moreover, if byte 1 contains a positive value at the start of the     *
 * input, then read assumes that number of characters are left over from *
 * an interrupted previous input, and writes the new characters after    *
 * those already there. Note that the interpreter does not redisplay the *
 * characters left over: the game does this, if it wants to. This is     *
 * unfortunate for any interpreter wanting to give input text a          *
 * distinctive appearance on-screen, but 'Beyond Zork', 'Zork Zero' and  *
 * 'Shogun' clearly require it. ("Just a tremendous pain in my butt" --  *
 * Andrew Plotkin; "the most unfortunate feature of the Z-machine        *
 * design" -- Stefan Jokisch.) In Version 4 and later, if the operands   *
 * time and routine are supplied (and non-zero) then the routine call    *
 * routine() is made every time/10 seconds during the keyboard-reading   *
 * process. If this routine returns true, all input is erased (to zero)  *
 * and the reading process is terminated at once. (The terminating       *
 * character code is 0.) The routine is permitted to print to the screen *
 * even if it returns false to signal "carry on": the interpreter should *
 * notice and redraw the input line so far, before input continues.      *
 * (Frotz notices by looking to see if the cursor position is at the     *
 * left-hand margin after the interrupt routine has returned.) If input  *
 * was terminated in the usual way, by the player typing a carriage      *
 * return, then a carriage return is printed (so the cursor moves to the *
 * next line). If it was interrupted, the cursor is left at the          *
 * rightmost end of the text typed in so far. Next, lexical analysis is  *
 * performed on the text (except that in Versions 5 and later, if        *
 * parse-buffer is zero then this is omitted). Initially, byte 0 of the  *
 * parse-buffer should hold the maximum number of textual words which    *
 * can be parsed. (If this is n, the buffer must be at least 2 + 4*n     *
 * bytes long to hold the results of the analysis.) The interpreter      *
 * divides the text into words and looks them up in the dictionary, as   *
 * described in S 13. The number of words is written in byte 1 and one   *
 * 4-byte block is written for each word, from byte 2 onwards (except    *
 * that it should stop before going beyond the maximum number of words   *
 * specified). Each block consists of the byte address of the word in    *
 * the dictionary, if it is in the dictionary, or 0 if it isn't;         *
 * followed by a byte giving the number of letters in the word; and      *
 * finally a byte giving the position in the text-buffer of the first    *
 * letter of the word. In Version 5 and later, this is a store           *
 * instruction: the return value is the terminating character (note that *
 * the user pressing his "enter" key may cause either 10 or 13 to be     *
 * returned; the author recommends that interpreters return 10). A       *
 * timed-out input returns 0. (Versions 1 and 2 and early Version 3      *
 * games mistakenly write the parse buffer length 240 into byte 0 of the *
 * parse buffer: later games fix this bug and write 59, because          *
 * 2+4*59 = 238 so that 59 is the maximum number of textual words which  *
 * can be parsed into a buffer of length 240 bytes. Old versions of the  *
 * Inform 5 library commit the same error. Neither mistake has very      *
 * serious consequences.) (Interpreters are asked to halt with a         *
 * suitable error message if the text or parse buffers have length of    *
 * less than 3 or 6 bytes, respectively: this sometimes occurs due to a  *
 * previous array being overrun, causing bugs which are very difficult   *
 * to find.)                                                             *
 *************************************************************************/
 
void opRead() {
	readString(0);
}

/*******************************
 * 1OP:137 9 remove_obj object *
 *************************************************************************
 * Detach the object from its parent, so that it no longer has any       *
 * parent. (Its children remain in its possession.)                      *
 *************************************************************************/
 
void opRemoveObj() {
	uint16_t Parent = getParent(Operand[0]);
	if(Parent != 0) {
		if(getChild(Parent) == Operand[0]) {
			setChild(Parent, getSibling(Operand[0]));
		} else {
			uint16_t LastChild = getChild(Parent);
			while(getSibling(LastChild) != Operand[0])
				LastChild = getSibling(LastChild);
			setSibling(LastChild, getSibling(Operand[0]));
		}
	}
	setParent(Operand[0], 0);
	setSibling(Operand[0], 0);
}

/***********************
 * 1OP:139 B ret value *
 *************************************************************************
 * Returns from the current routine with the value given.                *
 *************************************************************************/

void opRet() {
	popZFrame();
	if(CurrentZFrame->ReturnVar == 1)
		setZVar(getByte(CurrentZFrame->PC++), Operand[0]);
	CurrentZFrame->ReturnVar = 1;
}

/************************
 * 0OP:184 8 ret_popped *
 *************************************************************************
 * Pops top of stack and returns that. (This is equivalent to ret sp,    *
 * but is one byte cheaper.)                                             *
 *************************************************************************/

void opRetPopped() {
	Operand[0] = popZStack();
	opRet();
}

/********************
 * 0OP:177 1 rfalse *
 *************************************************************************
 * Return false (i.e., 0) from the current routine.                      *
 *************************************************************************/
 
void opRfalse() {
	Operand[0] = 0;
	opRet();
}

/*******************
 * 0OP:176 0 rtrue *
 *************************************************************************
 * Return true (i.e., 1) from the current routine.                       *
 *************************************************************************/

void opRtrue() {
	Operand[0] = 1;
	opRet();
}

/**************************************
 * 2OP:11 B set_attr object attribute *
 *************************************************************************
 * Make object have the attribute numbered attribute.                    *
 *************************************************************************/
 
void opSetAttr() {
	setObjectFlagValue(Operand[0], Operand[1], 1);
}

/***********************************
 * 2OP:13 D store (variable) value *
 *************************************************************************
 * Set the VARiable referenced by the operand to value.                  *
 *************************************************************************/
 
void opStore() {
	setZVar(Operand[0],Operand[1]);
}

/*******************************************
 * VAR:226 2 storeb array byte-index value *
 *************************************************************************
 * array->byte-index = value, i.e. stores the given value in the byte at *
 * address array+byte-index (which must lie in dynamic memory).          *
 * (See loadb.)                                                          *
 *************************************************************************/

void opStoreb() {
	setByte(Operand[0]+Operand[1], Operand[2]);
}

/*******************************************
 * VAR:225 1 storew array word-index value *
 *************************************************************************
 * array-->word-index = value, i.e. stores the given value in the word   *
 * at address array+2*word- index (which must lie in dynamic memory).    *
 *  (See loadw.)                                                         *
 *************************************************************************/

void opStorew() {
	setWord(Operand[0]+2*Operand[1], Operand[2]);
}

/*********************************
 * 2OP:21 15 sub a b -> (result) *
 *************************************************************************
 * Signed 16-bit subtraction.                                            *
 *************************************************************************/

void opSub() {
	int16_t Value = (int16_t)Operand[0];
	int16_t Smaller = (int16_t)Operand[1];
	zStore((uint16_t)(Value - Smaller)&0xFFFF);
}

/**************************************
 * 2OP:7 7 test bitmap flags ?(label) *
 *************************************************************************
 * Jump if all of the flags in bitmap are set (i.e. if bitmap & flags == *
 * flags).                                                               *
 *************************************************************************/

void opTest() {
	zBranch((Operand[0] & Operand[1]) == Operand[1]);
}

/************************************************
 * 2OP:10 A test_attr object attribute ?(label) *
 *************************************************************************
 * Jump if object has attribute.                                         *
 *************************************************************************/ 

void opTestAttr() {
	zBranch(getObjectFlag(Operand[0], Operand[1]));
}

/*****************************************
 * 2OP:28 1C 5/6 throw value stack-frame *
 *************************************************************************
 * Opposite of catch: resets the routine call state to the state it had  *
 *  when the given stack frame value was 'caught', and then returns. In  *
 * other words, it returns as if from the routine which executed the     *
 * catch which found this stack frame value.                             *
 *************************************************************************/

void opThrow() {
	if(Operand[1] > zFrameNumber(CurrentZFrame)) {
		fputs("Tried to throw bad frame pointer.\n",stderr);
		exit(1);
	}
	while(Operand[1] < zFrameNumber(CurrentZFrame))
		popZFrame();
	opRet();
}

/* --------------------------------------------------------------------- */

void initOpCodes() {
	for(int I = 0; I < 256; I++)
		CallOpCode[I] = &opNonexistant;
	for(int I = 0; I < 7; I++) {
		CallOpCode[0+32*I] = &opNop;
		CallOpCode[1+32*I] = &opJe;
		CallOpCode[2+32*I] = &opJl;
		CallOpCode[3+32*I] = &opJg;
		CallOpCode[4+32*I] = &opDecChk;
		CallOpCode[5+32*I] = &opIncChk;
		CallOpCode[6+32*I] = &opJin;
		CallOpCode[7+32*I] = &opTest;
		CallOpCode[8+32*I] = &opOr;
		CallOpCode[9+32*I] = &opAnd;
		CallOpCode[10+32*I] = &opTestAttr;
		CallOpCode[11+32*I] = &opSetAttr;
		CallOpCode[12+32*I] = &opClearAttr;
		CallOpCode[13+32*I] = &opStore;
		CallOpCode[14+32*I] = &opInsertObj;
		CallOpCode[15+32*I] = &opLoadw;
		CallOpCode[16+32*I] = &opLoadb;
		CallOpCode[17+32*I] = &opGetProp;
		CallOpCode[18+32*I] = &opGetPropAddr;
		CallOpCode[20+32*I] = &opAdd;
		CallOpCode[21+32*I] = &opSub;
		CallOpCode[22+32*I] = &opMul;
		CallOpCode[23+32*I] = &opDiv;
		CallOpCode[24+32*I] = &opMod;
		if(getZRev() >= 4)
			CallOpCode[25+32*I] = &opCall;
		if(getZRev() >= 5)
			CallOpCode[26+32*I] = &opCallVN;
		if(getZRev() == 5 || getZRev() == 6)
			CallOpCode[28+32*I] = &opThrow;
	}
	for(int I = 0; I  < 32; I++) {
		CallOpCode[I+32*4] = &opNonexistant;
		CallOpCode[I+32*5] = &opNonexistant;
	}
	for(int I = 0; I < 3; I++) {
		CallOpCode[128+16*I] = &opJz;
		CallOpCode[129+16*I] = &opGetSibling;
		CallOpCode[130+16*I] = &opGetChild;
		CallOpCode[131+16*I] = &opGetParent;
		CallOpCode[133+16*I] = &opInc;
		CallOpCode[134+16*I] = &opDec;
		if(getZRev() >= 4)
			CallOpCode[136+16*I] = &opCall;
		CallOpCode[138+16*I] = &opPrintObj;
		CallOpCode[139+16*I] = &opRet;
		CallOpCode[140+16*I] = &opJump;
		CallOpCode[141+16*I] = &opPrintPaddr;
		CallOpCode[176+16*I] = &opRtrue;
		CallOpCode[177+16*I] = &opRfalse;
		CallOpCode[178+16*I] = &opPrint;
		CallOpCode[184+16*I] = &opRetPopped;
		CallOpCode[187+16*I] = &opNewLine;
	}
	CallOpCode[224] = &opCall;
	CallOpCode[225] = &opStorew;
	CallOpCode[226] = &opStoreb;
	CallOpCode[227] = &opPutProp;
	CallOpCode[228] = &opRead;
	CallOpCode[229] = &opPrintChar;
	CallOpCode[230] = &opPrintNum;
	CallOpCode[231] = &opRandom;
	CallOpCode[232] = &opPush;
	CallOpCode[233] = &opPull;
}

#endif /* OPCODES_H */
