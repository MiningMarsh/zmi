#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/********************
 * 0OP:177 1 rfalse *
 *************************************************************************
 * Return false (i.e., 0) from the current routine.                      *
 *************************************************************************/
 
void opRfalse() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "rfalse");
	Operand[0] = 0;
	opRet();
}
