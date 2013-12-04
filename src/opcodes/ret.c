#include "command.h"
#include "memory.h"
#include "routine.h"
#include "globalvars.h"
#include "log.h"

/***********************
 * 1OP:139 B ret value *
 *************************************************************************
 * Returns from the current routine with the value given.                *
 *************************************************************************/

void opRet() {
	if(VerboseDebug > 5) {
		log_Message(MNull, "opRet()", "Returning from routine.");
	}
	zReturn(Operand[0]);
}
