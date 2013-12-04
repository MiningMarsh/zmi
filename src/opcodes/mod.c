#include "stdlib.h"
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"

/*********************************
 * 2OP:24 18 mod a b -> (result) *
 *************************************************************************
 * Remainder after signed 16-bit division. Division by zero should halt  *
 * the interpreter with a suit-able error message.                       *
 *************************************************************************/

void opMod() {
	zword Base = zSign(Operand[0]);
	zword Dividend = zSign(Operand[1]);
	if(Dividend == 0) {
		log_Message(MFatal, "mod", "Modulus by zero.");
		exit(1);
	}
	zStore(zUnsign(Base % Dividend));
}
