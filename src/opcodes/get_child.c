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
	
	// Getting the child of object 0 is illegal.
	if(!Operand[0]) {
		log_Message(MFatal, "get_child", "Tried to get child of object 0.");
		exit(1);
	}
	
	// Get the address of the child.
	uzword Object = getChild(Operand[0]);
	
	// Branch based on it.
	zStore(Object);
	zBranch(Object);
}
