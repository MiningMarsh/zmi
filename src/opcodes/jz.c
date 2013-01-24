#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/***************************
 * 1OP:128 0 jz a ?(label) *
 *************************************************************************
 * Jump if a = 0.                                                        *
 *************************************************************************/

void opJz() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "jz");
	zBranch(!Operand[0]);
}
