#include "zint.h"
#include "command.h"
#include "memory.h"

/****************************
 * 1OP:134 6 dec (variable) *
 *************************************************************************
 * Decrement variable by 1. This is signed, so 0 decrements to -1.       *
 *************************************************************************/

void opDec() {
	zword Value = zSign(getZVar(Operand[0]));
	setZVar(Operand[0], zUnsign(--Value));
}

