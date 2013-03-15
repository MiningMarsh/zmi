#include "command.h"
#include "memory.h"

/***********************
 * 1OP:139 B ret value *
 *************************************************************************
 * Returns from the current routine with the value given.                *
 *************************************************************************/

void opRet() {
	popZFrame();
	if(CurrentZFrame->ReturnVar == 1)
		setZVar(getByte(CurrentZFrame->PC), Operand[0]);
	CurrentZFrame->PC++;
	CurrentZFrame->ReturnVar = 1;
}
