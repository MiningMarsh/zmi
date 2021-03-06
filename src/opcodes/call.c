#include <stdlib.h>
#include <stdio.h>
#include "log.h"
#include "command.h"
#include "globalvars.h"
#include "memory.h"
#include "routine.h"

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
	// Create a new blank stack frame.
	pushZFrame();
	
	// Expand the padded address to get the routine location.
	CurrentZFrame->PC = expandPaddedAddress(Operand[0]);
	
	// There is an extra routine offset for version 6 and 7 that we must append.
	if(getZRev() == 6 || getZRev() == 7) {
		// This offset is stored at offset 0x28 in the header.
		CurrentZFrame->PC += 8*getWord(0x28);
	}
	
	// If address 0 is called, we instantly return 0 and nothing happens.
	if(!CurrentZFrame->PC) {
		zReturn(0);
		return;
	}

	// Check if it is out of memory range.
	if(CurrentZFrame->PC > 0xFFFFFFF || CurrentZFrame->PC > RAMSize ) {
		// Log an error message if it is.
		log_Message(
			MFatal, 
			"call",
			"Address %u expands to %u, which is out of memory range.\n"
			"Memory size is: %u",
			Operand[0],
			CurrentZFrame->PC,
			RAMSize
		);
		exit(1);
	}
	// Get the number of local variables the routine has.
	uzbyte NumberLocals = getByte(CurrentZFrame->PC++);
	// Allocate room for the locals.
	if(NumberLocals > 15) {
		log_Message(
			MFatal, 
			"call",
			"Invalid number of locals to routine: %u\n"
			"Only up to 15 locals are allowed.",
			NumberLocals
		);
		exit(1);
	}
	CurrentZFrame->Locals = calloc(sizeof(uzword), NumberLocals+1);
	CurrentZFrame->Locals[0] = NumberLocals;
	// Special handling for revision 3 and lower.
	if(getZRev() <= 3) {
		// Revision 3 and lower define default values for all routine
		// arguments. Get them and assign them here. revisions 4 and up 
		// use 0 for all default values.
		for(char I = 1; I < CurrentZFrame->Locals[0] + 1; I++) {
			CurrentZFrame->Locals[(int)I] = getWord(CurrentZFrame->PC);
			CurrentZFrame->PC += 2;
		}
	}
	// Pass the supplied arguments to the routine being called
	// by putting them on the stack frame.
	for(char I = 1; I <= CurrentZFrame->OldFrame->PassedArgs - 1; I++) {
		if(NumberLocals >= I) {
			CurrentZFrame->Locals[(int)I] = Operand[(int)(I)];
		}
	}
}

