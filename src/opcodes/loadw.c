#include "routine.h"
#include "command.h"
#include "memory.h"

/***********************************************
 * 2OP:15 F loadw array word-index -> (result) *
 *************************************************************************
 * Stores array-->word-index (i.e., the word at address                  *
 * array+2*word-index, which must lie in static or dynamic memory).      *
 *************************************************************************/

void opLoadw() {
	zStore(getWord(Operand[0]+2*Operand[1]));
}
