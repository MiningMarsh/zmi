#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/*******************
 * 0OP:176 0 rtrue *
 *************************************************************************
 * Return true (i.e., 1) from the current routine.                       *
 *************************************************************************/

void opRtrue() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "rtrue");
	Operand[0] = 1;
	opRet();
}
