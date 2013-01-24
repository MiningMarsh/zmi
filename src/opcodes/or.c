#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/******************************
 * 2OP:8 8 or a b -> (result) *
 *************************************************************************
 * Bitwise OR.                                                           *
 *************************************************************************/

void opOr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "or");
	zStore(Operand[0] | Operand[1]);
}
