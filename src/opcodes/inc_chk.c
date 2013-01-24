#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/*********************************************
 * 2OP:5 5 inc_chk (variable) value ?(label) *
 *************************************************************************
 * Increment variable, and branch if now greater than value.             *
 *************************************************************************/
 
void opIncChk() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "inc_chk");
	// Check the new value;
	zword Variable = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(++Variable));
	zword Value = zSign(Operand[1]);
	zBranch(Variable > Value);
}
