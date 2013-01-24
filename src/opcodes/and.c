#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"

/*******************************
 * 2OP:9 9 and a b -> (result) *
 *************************************************************************
 * Bitwise AND.                                                          *
 *************************************************************************/

void opAnd() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "and");
	// Store operand 1 AND operand 2.
	zStore(Operand[0]&Operand[1]);
}
