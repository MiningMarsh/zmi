#include <stdio.h>
#include "log.h"
#include "command.h"
#include "globalvars.h"

/*****************************
 * VAR:230 6 print_num value *
 *************************************************************************
 * Print (signed) number in decimal.                                     *
 *************************************************************************/

void opPrintNum() {
	// TODO: Fix zPrint so that this can use that instead of printf.
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print_num");
	printf("%i",Operand[0]);
}

