#include <stdlib.h>
#include "log.h"

/*********
 * DUMMY *
 *************************************************************************
 * A dummy opcode that should crash the interpreter. This gets executed  *
 * when a bad opcode is detected.                                        *
 *************************************************************************/

void opNonexistant() {
	log_Message(MFatal, "opNonexistant()", "Tried to execute nonexistant opcode!");
	exit(1);
}

