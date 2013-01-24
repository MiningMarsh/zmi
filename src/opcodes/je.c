#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/***************************
 * 2OP:1 1 je a b ?(label) *
 *************************************************************************
 * Jump if a is equal to any of the subsequent operands. (Thus @je a     *
 * never jumps and @je a b jumps if a = b.)                              *
 *************************************************************************/

void opJe() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "je");
	zBranch(Operand[0] == Operand[1]);
}
