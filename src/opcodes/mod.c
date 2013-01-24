#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/*********************************
 * 2OP:24 18 mod a b -> (result) *
 *************************************************************************
 * Remainder after signed 16-bit division. Division by zero should halt  *
 * the interpreter with a suit-able error message.                       *
 *************************************************************************/

void opMod() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "mod");
	zword Base = zSign(Operand[0]);
	zword Dividend = zSign(Operand[1]);
	if(Dividend == 0) {
		logMessage(MFatal, "mod", "Modulus by zero.");
		exit(1);
	}
	zStore(zUnsign((Base % Dividend)&0xFFFF));
}
