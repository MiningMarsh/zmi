#include <stdlib.h>
#include "log.h"

/*********************
 * 0OP:180 4 1/- nop *
 *************************************************************************
 * Probably the official "no operation" instruction, which,              *
 * appropriately, was never operated (in any of the Infocom datafiles):  *
 * it may once have been a breakpoint.                                   *
 *************************************************************************/
 
void opNop() {
	// This is "probably" standard compliant.
	logMessage(MWarning, "nop", 
		"Nop wastes both cpu cycles, and is\n"
		"not fully defined in the standard,\n"
		"and is therefore undefined\n"
		"behavior. Don't use it."
	);
}
