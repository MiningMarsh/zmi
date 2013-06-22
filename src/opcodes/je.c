#include "routine.h"
#include "command.h"
#include "memory.h"

/***************************
 * 2OP:1 1 je a b ?(label) *
 *************************************************************************
 * Jump if a is equal to any of the subsequent operands. (Thus @je a     *
 * never jumps and @je a b jumps if a = b.)                              *
 *************************************************************************/

void opJe() {
	switch(CurrentZFrame->PassedArgs) {
	case 1:
		break;
	case 4:
		if(Operand[0] == Operand[3]) {
			zBranch(1);
			return;
		}
	case 3:
		if(Operand[0] == Operand[2]) {
			zBranch(1);
			return;
		}
	case 2:
		if(Operand[0] == Operand[1]) {
			zBranch(1);
			return;
		}
		break;
	}
	zBranch(0);
}
