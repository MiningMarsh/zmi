#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/**************************************
 * 2OP:7 7 test bitmap flags ?(label) *
 *************************************************************************
 * Jump if all of the flags in bitmap are set (i.e. if bitmap & flags == *
 * flags).                                                               *
 *************************************************************************/

void opTest() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "test");
	zBranch((Operand[0] & Operand[1]) == Operand[1]);
}

