#include "zint.h"
#include "routine.h"
#include "command.h"
#include "memory.h"

/***********************************************
 * 2OP:4 4 dec_check (variable) value ?(label) *
 *************************************************************************
 * Decrement variable, and branch if it is now less than the given       *
 * value.                                                                *
 *************************************************************************/

void opDecChk() {
	// Check the new value;
	zword Variable = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(--Variable));
	zword Value = zSign(Operand[1]);
	zBranch(Variable < Value);
}
