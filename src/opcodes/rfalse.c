#include "command.h"
#include "opcodes.h"

/********************
 * 0OP:177 1 rfalse *
 *************************************************************************
 * Return false (i.e., 0) from the current routine.                      *
 *************************************************************************/
 
void opRfalse() {
	Operand[0] = 0;
	opRet();
}
