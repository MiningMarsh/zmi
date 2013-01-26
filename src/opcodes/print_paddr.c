#include <stdlib.h>
#include "command.h"
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
	char* String = zCharsToZSCII(getZChars(expandPaddedAddress(Operand[0])));
	zPrint(String);
	free(String);
}
