#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "object.h"
#include "memory.h"

/*******************************************************
 * 2OP:18 12 get_prop_addr object property -> (result) *
 *************************************************************************
 * Get the byte address (in dynamic memory) of the property data for the *
 * given object's property. This must return 0 if the property doesn't   *
 * exist.                                                                *
 *************************************************************************/

void opGetPropAddr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "get_prop_addr");
	uzword Address = getPropertyAddress(Operand[0], Operand[1]);
	if(Address)
		Address++;
	zStore(Address);
}
