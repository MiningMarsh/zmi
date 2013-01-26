#include "zint.h"
#include "routine.h"
#include "command.h"

/*********************************
 * 2OP:21 15 sub a b -> (result) *
 *************************************************************************
 * Signed 16-bit subtraction.                                            *
 *************************************************************************/

void opSub() {
	zword Value = zSign(Operand[0]);
	zword Smaller = zSign(Operand[1]);
	zStore(zUnsign(Value - Smaller));
}
