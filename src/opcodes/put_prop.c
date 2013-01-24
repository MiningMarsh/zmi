#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "memory.h"
#include "object.h"

/********************************************
 * VAR:227 3 put_prop object property value *
 *************************************************************************
 * Writes the given value to the given property of the given object. If  *
 * the property does not exist for that object, the interpreter should   *
 * halt with a suitable error message. If the property length is 1, then *
 * the interpreter should store only the least significant byte of the   *
 * value. (For instance, storing -1 into a 1-byte property results in    *
 * the property value 255.) As with get_prop the property length must    *
 * not be more than 2: if it is, the behaviour of the opcode is          *
 * undefined.                                                            *
 *************************************************************************/

void opPutProp() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "put_prop");
	uzword Address = getPropertyAddress(Operand[0],Operand[1]);
	uzbyte Size = ((getByte(Address++) - Operand[1])/32) + 1;
	if(Size == 1) {
		setByte(Address,Operand[2]);
	} else if(Size == 2) {
		setWord(Address, Operand[2]);
	} else {
		logMessage(MFatal, "put_prop", "Property size is greater then 2.");
		exit(1);
	}
}