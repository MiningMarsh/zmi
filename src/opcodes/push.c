#include "command.h"
#include "memory.h"

/************************
 * VAR:232 8 push value *
 *************************************************************************
 * Pushes value onto the game stack.                                     *
 *************************************************************************/

void opPush() {
	pushZStack(Operand[0]);
}
