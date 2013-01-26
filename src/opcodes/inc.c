#include "zint.h"
#include "command.h"
#include "memory.h"

/****************************
 * 1OP:133 5 inc (variable) *
 *************************************************************************
 * Increment variable by 1. (This is signed, so -1 increments to 0.)     *
 *************************************************************************/

void opInc() {
	zword Value = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(++Value));
}
