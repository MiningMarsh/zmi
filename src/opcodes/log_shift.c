#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/*************************************************
 * EXT:2 2 5 log_shift number places -> (result) *
 *************************************************************************
 * Does a logical shift of number by the given number of places,         *
 * shifting left (i.e. increasing) if places is positive, right if       *
 * negative. In a right shift, the sign is zeroed instead of being       *
 * shifted on. (See also art_shift.)                                     *
 *************************************************************************/

void opLogShift() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "log_shift");
	uzword Number = zSign(Operand[0]);
	zword Places = zSign(Operand[1]);
	if(Places >= 0)
		Number = Number << Places;
	else
		Number = Number >> (Places*(-1));
	zStore(zUnsign(Number));
}
