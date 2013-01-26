#include "routine.h"
#include "command.h"

/**************************************
 * 2OP:7 7 test bitmap flags ?(label) *
 *************************************************************************
 * Jump if all of the flags in bitmap are set (i.e. if bitmap & flags == *
 * flags).                                                               *
 *************************************************************************/

void opTest() {
	zBranch((Operand[0] & Operand[1]) == Operand[1]);
}

