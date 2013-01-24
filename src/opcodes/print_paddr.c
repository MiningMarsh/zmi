#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "output.h"
#include "zscii.h"
#include "memory.h"

/**************************************************
 * 1OP:141 D print_paddr packed-address-of-string *
 *************************************************************************
 * Print the (Z-encoded) string at the given packed address in high      *
 * memory.                                                               *
 *************************************************************************/

void opPrintPaddr() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print_paddr");
	char* String = zCharsToZSCII(getZChars(expandPaddedAddress(Operand[0])));
	zPrint(String);
	free(String);
}
