#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"

/**********************************
 * 2OP:6 6 jin obj1 obj2 ?(label) *
 *************************************************************************
 * Jump if object a is a direct child of b, i.e., if parent of a is b.   *
 *************************************************************************/

void opJin() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "jin");
	zBranch(getParent(Operand[0]) == Operand[1]);
}
