#include "command.h"
#include "memory.h"

/*******************************************
 * VAR:225 1 storew array word-index value *
 *************************************************************************
 * array-->word-index = value, i.e. stores the given value in the word   *
 * at address array+2*word- index (which must lie in dynamic memory).    *
 *  (See loadw.)                                                         *
 *************************************************************************/

void opStorew() {
	setWord(Operand[0]+2*Operand[1], Operand[2]);
}
