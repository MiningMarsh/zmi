#include <stdlib.h>
#include "command.h"
#include "log.h"
#include "zint.h"
#include "object.h"

/*******************************
 * 1OP:137 9 remove_obj object *
 *************************************************************************
 * Detach the object from its parent, so that it no longer has any       *
 * parent. (Its children remain in its possession.)                      *
 *************************************************************************/
 
void opRemoveObj() {
	if(!Operand[0]) {
		logMessage(MFatal, "remove_obj", "Tried to remove object 0 from the object tree.");
		exit(1);
	}
	// Get the objects parent.
	uzword Parent = getParent(Operand[0]);
	// If the object has no parent, there is nothing to detach it from.
	if(Parent) {
		// Check if the object is the direct child of its parent.
		if(getChild(Parent) == Operand[0]) {
			// If it is, we just need to set the child to the objects sibling
			// (i.e. the next child).
			setChild(Parent, getSibling(Operand[0]));
		} else {
			// else we need to find the child before the object.
			uzword LastChild = getChild(Parent);
			while(getSibling(LastChild) != Operand[0])
				LastChild = getSibling(LastChild);
			// Then set the sibling of that child to the sibling of the object.
			setSibling(LastChild, getSibling(Operand[0]));
		}
		// The object no longer has a parent.
		setParent(Operand[0], 0);
	}
	// The object has no siblings now either.
	setSibling(Operand[0], 0);
}
