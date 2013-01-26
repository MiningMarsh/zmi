#include "zint.h"
#include "routine.h"
#include "command.h"
#include "memory.h"

/*********************************************
 * 2OP:5 5 inc_chk (variable) value ?(label) *
 *************************************************************************
 * Increment variable, and branch if now greater than value.             *
 *************************************************************************/
 
void opIncChk() {
	zword Variable = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(++Variable));
	zword Value = zSign(Operand[1]);
	// Check the new value;
	zBranch(Variable > Value);
}
