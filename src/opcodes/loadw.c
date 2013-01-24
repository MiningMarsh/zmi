#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/***********************************************
 * 2OP:15 F loadw array word-index -> (result) *
 *************************************************************************
 * Stores array-->word-index (i.e., the word at address                  *
 * array+2*word-index, which must lie in static or dynamic memory).      *
 *************************************************************************/

void opLoadw() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "loadw");
	zStore(getWord(Operand[0]+2*Operand[1]));
}
