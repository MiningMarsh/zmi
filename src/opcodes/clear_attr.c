#include "command.h"
#include "object.h"

/****************************************
 * 2OP:12 C clear_attr object attribute *
 *************************************************************************
 * Make object not have the attribute numbered attribute.                *
 *************************************************************************/

void opClearAttr() {
	// Set the specified flag to 0.
	setObjectFlagValue(Operand[0], Operand[1], 0);
}

