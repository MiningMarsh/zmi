#include <stdlib.h>
#include "log.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/***************************************************
 * VAR:249 19 5 call_vn routine ...up to 3 args... *
 *************************************************************************
 * Like 'call', but throws away the result.                              *
 *************************************************************************/

void opCallVN () {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "CallVN");
	// Set up metadata saying this stackframe doesn't return anything.
	CurrentZFrame->ReturnVar = 0;
	// Transfer to a standard routine call.
	opCall();
}
