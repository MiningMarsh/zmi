#include "routine.h"
#include "zint.h"
#include "command.h"

/***************************
 * 2OP:2 2 jl a b ?(label) *
 *************************************************************************
 * Jump if a < b (using a signed 16-bit comparison).                     *
 * ***********************************************************************/

void opJl() {
	zword A = zSign(Operand[0]);
	zword B = zSign(Operand[1]);
	zBranch(A < B);
}

