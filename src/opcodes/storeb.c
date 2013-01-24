#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/*******************************************
 * VAR:226 2 storeb array byte-index value *
 *************************************************************************
 * array->byte-index = value, i.e. stores the given value in the byte at *
 * address array+byte-index (which must lie in dynamic memory).          *
 * (See loadb.)                                                          *
 *************************************************************************/

void opStoreb() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "storeb");
	setByte(Operand[0]+Operand[1], Operand[2]);
}
