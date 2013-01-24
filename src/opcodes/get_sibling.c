#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"

/*****************************************************
 * 1OP:129 1 get_sibling object -> (result) ?(label) *
 *************************************************************************
 * Get next object in tree, branching if this exists, i.e. is not 0.     *
 *************************************************************************/

 void opGetSibling() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "get_sibling");
	uzword Object = getSibling(Operand[0]);
	if(!Operand[0]) {
		logMessage(MFatal, "get_sibling", "Tried to get sibling of object 0.");
	//	exit(1);
		Object = 0;
	}
	zStore(getSibling(Operand[0]));
	zBranch(getSibling(Operand[0]));
}
