#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"

/**************************************
 * 2OP:11 B set_attr object attribute *
 *************************************************************************
 * Make object have the attribute numbered attribute.                    *
 *************************************************************************/
 
void opSetAttr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "set_attr");
	setObjectFlagValue(Operand[0], Operand[1], 1);
}

