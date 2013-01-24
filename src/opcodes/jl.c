#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/***************************
 * 2OP:2 2 jl a b ?(label) *
 *************************************************************************
 * Jump if a < b (using a signed 16-bit comparison).                     *
 * ***********************************************************************/

void opJl() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "jl");
	zBranch(Operand[0] < Operand[1]);
}

