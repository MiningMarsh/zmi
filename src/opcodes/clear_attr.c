#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"

/****************************************
 * 2OP:12 C clear_attr object attribute *
 *************************************************************************
 * Make object not have the attribute numbered attribute.                *
 *************************************************************************/

void opClearAttr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "clear_attr");
	// Set the specified flg to 0.
	setObjectFlagValue(Operand[0], Operand[1], 0);
}

