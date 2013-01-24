#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/*********************************
 * 2OP:21 15 sub a b -> (result) *
 *************************************************************************
 * Signed 16-bit subtraction.                                            *
 *************************************************************************/

void opSub() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "sub");
	zword Value = zSign(Operand[0]);
	zword Smaller = zSign(Operand[1]);
	zStore(zUnsign((Value - Smaller)&0xFFFF));
}
