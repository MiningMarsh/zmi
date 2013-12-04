#include <stdlib.h>
#include "log.h"
#include "routine.h"
#include "command.h"
#include "object.h"
#include "memory.h"

/**************************************************
 * 2OP:17 11 get_prop object property -> (result) *
 *************************************************************************
 * Read property from object (resulting in the default value if it had   *
 * no such declared property). If the property has length 1, the value   *
 * only that byte. If it has length of 2, the first two bytes of that    *
 * property is taken as a word value. It is illegal for the opcode to be *
 * if the property has length greater then 2, and the result is          *
 * unspecified.                                                          *
 *************************************************************************/

// Get a property of an object.
void opGetProp() {
	// Get the property address.
	if(propertyExists(Operand[0], Operand[1])) {
		zaddress Address = getPropertyValueAddress(Operand[0], Operand[1]);
		// If it existed, find its size.
		uzbyte Size = getPropertySize(Operand[0], Operand[1]);
		if(Size == 1) {
			zStore(getByte(Address));
		} else if(Size == 2) {
			zStore(getWord(Address));
		} else {
			log_Message(MFatal, "get_prop", "Property size is greater then 2.");
			exit(1);
		}
	} else {
		zStore(getDefaultPropertyValue(Operand[1]));
	}
}
