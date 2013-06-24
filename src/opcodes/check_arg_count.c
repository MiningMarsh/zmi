#include "routine.h"
#include "command.h"
#include "memory.h"

/************************************************
 * VAR:255 1F 5 check_arg_count argument-number *
 *************************************************************************
 * Branch if a given argument number (couting by 1) has been provided by *
 * the routine call to the current routine. (This allows routines in     *
 * 5 and later to distingiush between calls routine(1) and routine(1,0)  *
 * which would otherwise be impossible to tell apart.)                   *
 *************************************************************************/

void opCheckArgCount() {
	zBranch(Operand[0] <= CurrentZFrame->OldFrame->PassedArgs);
}
