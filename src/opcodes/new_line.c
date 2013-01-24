#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "output.h"

/**********************
 * 0OP:187 B new_line *
 *************************************************************************
 * Print carriage return.                                                *
 *************************************************************************/

// Print a newline.
void opNewLine() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "new_line");
	zPrint("\n");
}

