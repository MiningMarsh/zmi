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
	// The name is stored in the property table.
	uzword PropertyTableAddress = getPropertyTableAddress(Operand[0]);
	// The first byte of the property table is the length of the name, but 
	// we just extract that from the text bytes anyway.
	PropertyTableAddress++;
	// The next bytes are teh text bytes containing the object's name.
	char* ObjectName = zCharsToZSCII(getZChars(PropertyTableAddress));
	// Print the decoded name.
	zPrint(ObjectName);
	// Free teh used memory.
	free(ObjectName);
}
