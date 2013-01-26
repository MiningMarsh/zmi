#include "routine.h"
#include "command.h"

/***************************
 * 2OP:1 1 je a b ?(label) *
 *************************************************************************
 * Jump if a is equal to any of the subsequent operands. (Thus @je a     *
 * never jumps and @je a b jumps if a = b.)                              *
 *************************************************************************/

void opJe() {
	zBranch(Operand[0] == Operand[1]);
}
