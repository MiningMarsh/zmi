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
	uzword Parent = getParent(Operand[0]);
	if(Parent != 0) {
		if(getChild(Parent) == Operand[0]) {
			setChild(Parent, getSibling(Operand[0]));
		} else {
			uzword LastChild = getChild(Parent);
			while(getSibling(LastChild) != Operand[0])
				LastChild = getSibling(LastChild);
			setSibling(LastChild, getSibling(Operand[0]));
		}
		setParent(Operand[0], 0);
	}
	setSibling(Operand[0], 0);
}
