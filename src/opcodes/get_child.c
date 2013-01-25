#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "object.h"

/***************************************************
 * 1OP:130 2 get_child object -> (result) ?(label) *
 *************************************************************************
 * Get object contained in given object, branching if this exists, i.e.  *
 * is not nothing (i.e., is not 0).                                      *
 *************************************************************************/

void opGetChild() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "get_child");
	uzword Address = getChild(Operand[0]);
	if(!Operand[0]) {
		logMessage(MFatal, "get_child", "Tried to get object in object 0.");
		//exit(1);
		Address = 0;
	}
	// Get the address of the child.
	zStore(Address);
	zBranch(Address);
}
