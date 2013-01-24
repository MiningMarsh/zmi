#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/***************************
 * 2OP:3 3 jg a b ?(label) *
 *************************************************************************
 * Jump if a > b (using a signed 16-bit comparison).                     *
 *************************************************************************/

void opJg() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "jg");
	zword A = zSign(Operand[0]);
	zword B = zSign(Operand[1]);
	zBranch(A > B);
}
