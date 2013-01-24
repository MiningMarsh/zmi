#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "zscii.h"
#include "memory.h"
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
	// TODO: Implement %s in zprint to fix this potential code injection
	// exploit.
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print_obj");
	uzword PropertyTableAddress = getPropertyTableAddress(Operand[0]);
	 PropertyTableAddress++;
	char* ObjectName = zCharsToZSCII(getZChars( PropertyTableAddress));
	zPrint(ObjectName);
	free(ObjectName);
}
