#include "opcodes.h"
#include "memory.h"

/***************************************************
 * VAR:249 19 5 call_vn routine ...up to 3 args... *
 *************************************************************************
 * Like 'call', but throws away the result.                              *
 *************************************************************************/

void opCallVN () {
	// Set up metadata saying this stackframe doesn't return anything.
	CurrentZFrame->ReturnVar = 0;
	// Transfer to a standard routine call.
	opCall();
}
