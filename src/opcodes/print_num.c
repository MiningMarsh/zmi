#include <stdio.h>
#include "command.h"

/*****************************
 * VAR:230 6 print_num value *
 *************************************************************************
 * Print (signed) number in decimal.                                     *
 *************************************************************************/

void opPrintNum() {
	// TODO: Fix zPrint so that this can use that instead of printf.
	printf("%i",Operand[0]);
}

