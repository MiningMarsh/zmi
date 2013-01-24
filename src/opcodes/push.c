#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/************************
 * VAR:232 8 push value *
 *************************************************************************
 * Pushes value onto the game stack.                                     *
 *************************************************************************/

void opPush() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "push");
	pushZStack(Operand[0]);
}
