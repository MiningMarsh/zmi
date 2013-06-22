#include <stdlib.h>
#include "zint.h"
#include "log.h"
#include "routine.h"
#include "command.h"
#include "object.h"

/***************************************************
 * 1OP:130 2 get_child object -> (result) ?(label) *
 *************************************************************************
 * Get object contained in given object, branching if this exists, i.e.  *
 * is not nothing (i.e., is not 0).                                      *
 *************************************************************************/

void opGetChild() {
	if(!Operand[0]) {
		logMessage(MFatal, "get_child", "Tried to get object in object 0.");
		exit(1);
	}
	uzword Address = getChild(Operand[0]);
	// Get the address of the child.
	zStore(Address);
	zBranch(Address);
}
