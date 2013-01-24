#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/***********************************************
 * 2OP:4 4 dec_check (variable) value ?(label) *
 *************************************************************************
 * Decrement variable, and branch if it is now less than the given       *
 * value.                                                                *
 *************************************************************************/

void opDecChk() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "dec_chk");
	// Check the new value;
	zword Variable = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(--Variable));
	zword Value = zSign(Operand[1]);
	zBranch(Variable < Value);
}
