#include "routine.h"
#include "command.h"
#include "memory.h"

/************************************************
 * 2OP:16 10 loadb array byte-index -> (result) *
 *************************************************************************
 * Stores array->byte-index (i.e., the byte at address array+byte-index, *
 *  which must lie in static or dynamic memory).                         *
 *************************************************************************/

void opLoadb() {
	zStore(getByte(Operand[0]+Operand[1]));
}
