#include "opcodes.h"
#include "memory.h"

/*******************************************
 * 1OP:136 8 4 call_1s routine -> (result) *
 *************************************************************************
 * Stores routine().                                                     *
 *************************************************************************/

void opCall1S() {
	// Set up metadata saying this stackframe returns anything. While not needed,
	// better safe than sorry.
	CurrentZFrame->ReturnVar = 1;
	// Transfer to a standard routine call.
	opCall();
}
