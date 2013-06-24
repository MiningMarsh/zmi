#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"

/*********************************
 * 2OP:23 17 div a b -> (result) *
 *************************************************************************
 * Signed 16-bit division. Division by zero should halt the interpreter  *
 * with a suitable error message.                                        *
 *************************************************************************/

void opDiv() {
	zword Operator = zSign(Operand[0]);
	zword Dividend = zSign(Operand[1]);
	if(Dividend == 0) {
		logMessage(MFatal, "div", "Divide by zero.");
		exit(1);
	}
	zStore(zUnsign(Operator / Dividend));
}
