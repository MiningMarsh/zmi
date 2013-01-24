#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/************************************************
 * VAR:255 1F 5 check_arg_count argument-number *
 *************************************************************************
 * Branch if a given argument number (couting by 1) has been provided by *
 * the routine call to the current routine. (This allows routines in     *
 * 5 and later to distingiush between calls routine(1) and routine(1,0)  *
 * which would otherwise be impossible to tell apart.)                   *
 *************************************************************************/

void opCheckArgCount() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "check_arg_count");
	if(g_VerboseDebug >= 25) {
		char Message[256];
		sprintf(
			Message,
			"%u <= %u -> %u",
			Operand[0] - 1,
			CurrentZFrame->OldFrame->PassedArgs,
			Operand[0] - 1 <= CurrentZFrame->OldFrame->PassedArgs
		);
		logMessage(MNull, "check_arg_count", Message);
	}
	zBranch(Operand[0] - 1 <= CurrentZFrame->OldFrame->PassedArgs);
}
