#include <stdio.h>
#include "log.h"
#include "routine.h"
#include "globalvars.h"
#include "memory.h"

/***********************************
 * 0OP:185 0 5/6 catch -> (result) *
 *************************************************************************
 * Opposite to 'throw' (and occupying the same opcode that 'pop' used in *
 * Version 3 and 4.) 'catch' returns the current stackframe.             *
 *************************************************************************/

void opCatch() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "catch");
	if(g_VerboseDebug >= 25) {
		char Message[256];
		sprintf(
			Message,
			"Frame number: %u",
			zFrameNumber(CurrentZFrame)
		);
		logMessage(MNull, "catch", Message);
	}
	zStore(zFrameNumber(CurrentZFrame));
}
