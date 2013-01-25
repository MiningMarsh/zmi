#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/*****************************************
 * 2OP:28 1C 5/6 throw value stack-frame *
 *************************************************************************
 * Opposite of catch: resets the routine call state to the state it had  *
 *  when the given stack frame value was 'caught', and then returns. In  *
 * other words, it returns as if from the routine which executed the     *
 * catch which found this stack frame value.                             *
 *************************************************************************/

void opThrow() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "throw");
	if(Operand[1] > zFrameNumber(CurrentZFrame)) {
		logMessage(MFatal, "opThrow()", "Tried to throw bad frame pointer");
		exit(1);
	}
	while(Operand[1] < zFrameNumber(CurrentZFrame))
		popZFrame();
	opRet();
}
