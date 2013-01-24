#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/****************************
 * 1OP:133 5 inc (variable) *
 *************************************************************************
 * Increment variable by 1. (This is signed, so -1 increments to 0.)     *
 *************************************************************************/

void opInc() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "inc");
	zword Value = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(++Value));
}
