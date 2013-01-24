#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/***********************
 * 0OP:179 3 print_ret *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string, then print a new-line    *
 * and then return true (i.e., 1).                                       *
 *************************************************************************/

void opPrint();
void opNewLine();
void opRtrue();

void opPrintRet() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print_ret");
	opPrint();
	opNewLine();
	opRtrue();
}
