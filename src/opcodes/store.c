#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/***********************************
 * 2OP:13 D store (variable) value *
 *************************************************************************
 * Set the VARiable referenced by the operand to value.                  *
 *************************************************************************/
 
void opStore() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "store");
	setZVar(Operand[0],Operand[1]);
}
