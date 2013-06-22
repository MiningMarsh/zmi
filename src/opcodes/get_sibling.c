#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "object.h"

/*****************************************************
 * 1OP:129 1 get_sibling object -> (result) ?(label) *
 *************************************************************************
 * Get next object in tree, branching if this exists, i.e. is not 0.     *
 *************************************************************************/

 void opGetSibling() {
	if(!Operand[0]) {
		logMessage(MFatal, "get_sibling", "Tried to get sibling of object 0.");
		exit(1);
	}
	uzword Object = getSibling(Operand[0]);
	zStore(Object);
	zBranch(Object);
}
