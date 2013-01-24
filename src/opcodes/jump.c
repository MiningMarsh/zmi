#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"

/***************************
 * 1OP:140 C jump ?(label) *
 *************************************************************************
 * Jump (unconditionally) to the given label. (This is not a branch      *
 * instruction and the operand is a 2-byte signed offset to apply to the *
 * program counter.) It is legal for this to jump into a different       *
 * routine (which should not change the routine call state), although it *
 * is considered bad practice to do so and the Txd disassembler is       *
 * confused by it.                                                       *
 *************************************************************************/

void opJump() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "jump");
	CurrentZFrame->PC += zSign(Operand[0]) - 2;
}
