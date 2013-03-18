#include "command.h"
#include "opcodes.h"
#include "memory.h"

/************************
 * 0OP:184 8 ret_popped *
 *************************************************************************
 * Pops top of stack and returns that. (This is equivalent to ret sp,    *
 * but is one byte cheaper.)                                             *
 *************************************************************************/

void opRetPopped() {
	// Get the value from the stack.
	Operand[0] = popZStack();
	// Transfer to standard return call.
	opRet();
}
