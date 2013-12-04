#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "object.h"

/*******************************************
 * 1OP:131 3 get_parent object -> (result) *
 *************************************************************************
 * Get parent object (note this has no "banch if exists" clause).        *
 *************************************************************************/

void opGetParent() {
	if(!Operand[0]) {
		log_Message(MFatal, "get_parent", "Tried to get parent of object 0.");
		exit(1);
	}
	uzword Object = getParent(Operand[0]);
	zStore(Object);
}
