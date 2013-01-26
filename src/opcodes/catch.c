#include "routine.h"
#include "memory.h"

/***********************************
 * 0OP:185 0 5/6 catch -> (result) *
 *************************************************************************
 * Opposite to 'throw' (and occupying the same opcode that 'pop' used in *
 * Version 3 and 4.) 'catch' returns the current stackframe.             *
 *************************************************************************/

void opCatch() {
	zStore(zFrameNumber(CurrentZFrame));
}
