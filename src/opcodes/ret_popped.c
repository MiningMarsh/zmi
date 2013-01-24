#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/************************
 * 0OP:184 8 ret_popped *
 *************************************************************************
 * Pops top of stack and returns that. (This is equivalent to ret sp,    *
 * but is one byte cheaper.)                                             *
 *************************************************************************/

void opRetPopped() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "ret_popped");
	Operand[0] = popZStack();
	opRet();
}