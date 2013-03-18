#include "command.h"
#include "memory.h"
#include "routine.h"

/***********************
 * 1OP:139 B ret value *
 *************************************************************************
 * Returns from the current routine with the value given.                *
 *************************************************************************/

void opRet() {
	zReturn(Operand[0]);
}
