#include "zint.h"
#include "routine.h"
#include "command.h"

/*********************************
 * 2OP:22 16 mul a b -> (result) *
 *************************************************************************
 * Signed 16-bit multiplication.                                         *
 *************************************************************************/
 
void opMul() {
	zword Multiple = zSign(Operand[0]);
	zword Multiplied = zSign(Operand[1]);
	zStore(zUnsign(Multiple * Multiplied));
}
