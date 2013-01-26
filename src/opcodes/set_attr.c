#include "command.h"
#include "object.h"

/**************************************
 * 2OP:11 B set_attr object attribute *
 *************************************************************************
 * Make object have the attribute numbered attribute.                    *
 *************************************************************************/
 
void opSetAttr() {
	setObjectFlagValue(Operand[0], Operand[1], 1);
}

