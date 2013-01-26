#include "routine.h"
#include "command.h"
#include "object.h"

/************************************************
 * 2OP:10 A test_attr object attribute ?(label) *
 *************************************************************************
 * Jump if object has attribute.                                         *
 *************************************************************************/ 

void opTestAttr() {
	zBranch(getObjectFlag(Operand[0], Operand[1]));
}
