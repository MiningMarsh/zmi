#include <stdlib.h>
#include "log.h"
#include "command.h"
#include "globalvars.h"
#include "memory.h"

/*******************************************
 * VAR:225 1 storew array word-index value *
 *************************************************************************
 * array-->word-index = value, i.e. stores the given value in the word   *
 * at address array+2*word- index (which must lie in dynamic memory).    *
 *  (See loadw.)                                                         *
 *************************************************************************/

void opStorew() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "storew");
	setWord(Operand[0]+2*Operand[1], Operand[2]);
}
