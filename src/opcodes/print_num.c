#include <stdio.h>
#include "command.h"
#include "output.h"

/*****************************
 * VAR:230 6 print_num value *
 *************************************************************************
 * Print (signed) number in decimal.                                     *
 *************************************************************************/

void opPrintNum() {
	char String[256];
	sprintf(String, "%i", Operand[0]);
	zPrint(String);
}

