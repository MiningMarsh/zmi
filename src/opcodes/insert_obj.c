#include "command.h"
#include "zint.h"
#include "opcodes.h"
#include "object.h"

/******************************************
 * 2OP:14 E insert_obj object destination *
 *************************************************************************
 * Moves object O to become the first child of the destination object D. *
 * (Thus, after the operation the child of D is O, and the sibling of O  *
 * is whatever was previously the child of D.) All children of O move    *
 * with it. (Initially O can be at any point in the object tree; it may  *
 * legally have parent zero.)                                            *
 *************************************************************************/
 
void opInsertObj() {
	opRemoveObj();
	uzword Child = getChild(Operand[1]);
	setSibling(Operand[0], Child);
	setParent(Operand[0], Operand[1]);
	setChild(Operand[1], Operand[0]);
}
