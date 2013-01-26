#include "zint.h"
#include "routine.h"
#include "command.h"

/***************************
 * 2OP:3 3 jg a b ?(label) *
 *************************************************************************
 * Jump if a > b (using a signed 16-bit comparison).                     *
 *************************************************************************/

void opJg() {
	zword A = zSign(Operand[0]);
	zword B = zSign(Operand[1]);
	zBranch(A > B);
}
