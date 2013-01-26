#include "command.h"
#include "opcodes.h"

/*******************
 * 0OP:176 0 rtrue *
 *************************************************************************
 * Return true (i.e., 1) from the current routine.                       *
 *************************************************************************/

void opRtrue() {
	Operand[0] = 1;
	opRet();
}
