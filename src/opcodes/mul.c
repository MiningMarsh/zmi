#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/*********************************
 * 2OP:22 16 mul a b -> (result) *
 *************************************************************************
 * Signed 16-bit multiplication.                                         *
 *************************************************************************/
 
void opMul() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "mul");
	zword Multiple = zSign(Operand[0]);
	zword Multiplied = zSign(Operand[1]);
	zStore(zUnsign(Multiple * Multiplied));
}
