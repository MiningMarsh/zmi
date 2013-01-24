#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"

/************************************************
 * 2OP:10 A test_attr object attribute ?(label) *
 *************************************************************************
 * Jump if object has attribute.                                         *
 *************************************************************************/ 

void opTestAttr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "test_attr");
	zBranch(getObjectFlag(Operand[0], Operand[1]));
}
