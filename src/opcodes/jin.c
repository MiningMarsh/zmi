#include "routine.h"
#include "command.h"
#include "object.h"

/**********************************
 * 2OP:6 6 jin obj1 obj2 ?(label) *
 *************************************************************************
 * Jump if object a is a direct child of b, i.e., if parent of a is b.   *
 *************************************************************************/

void opJin() {
	zBranch(getParent(Operand[0]) == Operand[1]);
}
