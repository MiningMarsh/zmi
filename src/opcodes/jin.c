#include <stdlib.h>
#include "routine.h"
#include "command.h"
#include "object.h"
#include "log.h"

/**********************************
 * 2OP:6 6 jin obj1 obj2 ?(label) *
 *************************************************************************
 * Jump if object a is a direct child of b, i.e., if parent of a is b.   *
 *************************************************************************/

void opJin() {
	if(!Operand[0]) {
		logMessage(MFatal, "jin", "Tried to get parent of object 0.");
		exit(1);
	}
	zBranch(getParent(Operand[0]) == Operand[1]);
}
