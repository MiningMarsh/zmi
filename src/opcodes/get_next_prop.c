#include <stdlib.h>
#include "log.h"
#include "routine.h"
#include "command.h"
#include "object.h"
#include "memory.h"

/*******************************************************
 * 2OP:19 13 get_next_prop object property -> (result) *
 *************************************************************************
 * Gives the number of the next property provided by the quoted object.  *
 * This may be zero, indicating the end of the property list; if called  *
 * with zero, it gives the first property number present. It is illegal  *
 * to try to find the next property of a property which does not exist,  *
 * and an interpreter should halt with an error message (if it can       *
 * efficiently check this condition).                                    *
 *************************************************************************/

// Get a property of an object.
void opGetNextProp() {
	uzword PropertyNumber = Operand[1];
	if(PropertyNumber) {
		if(!propertyExists(Operand[0], PropertyNumber++)) {
			logMessage(MFatal, "get_next_prop", "Tried to get next property of nonexistant property.");
			exit(1);
		}
	}
	for(; PropertyNumber <= (getZRev() < 4 ? 0xFF : 0xFFFF); PropertyNumber++) {
		if(propertyExists(Operand[0], PropertyNumber)) {
			zStore(PropertyNumber);
			return;
		}
	}
	zStore(0);
}
