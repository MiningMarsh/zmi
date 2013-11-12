#include <stdlib.h>
#include "memory.h"
#include "routine.h"
#include "command.h"
#include "object.h"
#include "log.h"

/*******************************************************
 * 1OP:132 4 get_prop_len property-address -> (result) *
 *************************************************************************
 * Get length of piroperty data (in bytes) for the given object's        *
 * property. It is illegal to try to find the property length of a       *
 * property that does not exist for the given object, and the            *
 * interpreter should halt with an error message (if it can efficiently  *
 * check for this condition).                                            *
 *************************************************************************/

void opGetPropLen() {
	if(!propertyExists(Operand[0], Operand[1])) {
		logMessage(
			MFatal,
			"get_prop_len",
			"Tried to get length of nonexistant property."
		);
		exit(1);
	}
	
	zaddress Address = getPropertyAddress(Operand[0], Operand[1]);
	
	if(getZRev() < 4) {
		zStore((getByte(Address)>>5) + 1);
		return;
	} 
	
	uzword Size = 0;
	uzword PropertyData = getByte(Address);
	if((PropertyData>>7)&1) {
		Size = (getByte(++Address)&63);
		if(!Size)
			Size = 64;
	} else {
		Size = ((PropertyData>>6)&1)+1;
	}
	zStore(Size);
}
