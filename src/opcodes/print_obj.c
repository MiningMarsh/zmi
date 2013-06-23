#include <stdlib.h>
#include "zint.h"
#include "command.h"
#include "zscii.h"
#include "output.h"
#include "object.h"

/******************************
 * 1OP:138 A print_obj object *
 *************************************************************************
 * Print short name of object (the Z-encoded string in the object        * 
 * header, not a property). If the object number is invalid, the         *
 * interpreter should halt with a suitable error message.                *
 *************************************************************************/

void opPrintObj() {
	uzword PropertyTableAddress = getPropertyTableAddress(Operand[0]);
	PropertyTableAddress++;
	char* ObjectName = zCharsToZSCII(getZChars(PropertyTableAddress));
	zPrint(ObjectName);
	free(ObjectName);
}
