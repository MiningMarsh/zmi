#include <stdlib.h>
#include "command.h"
#include "output.h"
#include "zscii.h"

/***********************************************
 * 1OP:135 7 print_addr byte-address-of-string *
 *************************************************************************
 * Print (Z-encoded) string at given byte address, in dynamic or static  *
 * memory.                                                               *
 *************************************************************************/

void opPrintAddr() {
	char* String = zCharsToZSCII(getZChars(Operand[0]));
	zPrint(String);
	free(String);
}
