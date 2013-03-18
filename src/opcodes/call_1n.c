#include "opcodes.h"
#include "memory.h"

/*******************************
 * 1OP:143 F 5 call_1n routine *
 *************************************************************************
 * Executes routine() and throws away result.                            *
 *************************************************************************/

void opCall1N() {
	// Set up metadata saying this stackframe doesn't return anything.
	CurrentZFrame->ReturnVar = 0;
	// Transfer to a standard routine call.
	opCall();
}
