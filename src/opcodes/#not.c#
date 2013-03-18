#include <stdio.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"

/******************************************
 * 1OP:143 F  1/4 not value -> (result)   *
 * VAR:248 18 5/6 not value -> (result)   *
 *****************************************************************************************************
 * Bitwise NOT (i.e., all 16 bits revers). Note that in versions 3 and 4, this is a 1OP instruction, *
 * reasonably since it has 1 operand, but in later Versions it was moved into the extended set to    *
 * make room for call_1n.                                                                            *
 *****************************************************************************************************/


void opNot() {
	uzword Number = Operand[0]; //Get the number to reverse
	Number ^= 0xFFFF; //negate the bits
	zStore(Number); //store the result	
}
