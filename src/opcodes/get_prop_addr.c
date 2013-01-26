#include "routine.h"
#include "command.h"
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
	if(!propertyExists(Operand[0], Operand[1])) {
		zStore(0);
		return;
	}
	zStore(getPropertyValueAddress(Operand[0], Operand[1]));
}
