#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "command.h"
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
	// Get the property address.
	if(propertyExists(Operand[0], Operand[1])) {
		zaddress Address = getPropertyValueAddress(Operand[0], Operand[1]);
		// If it existed, find its size.
		uzbyte Size = getPropertySize(Operand[0], Operand[1]);
		if(Size == 1) {
			setByte(Address, Operand[2]&0xFF);
		} else if(Size == 2) {
			setWord(Address, Operand[2]);
		} else {
			log_Message(MFatal, "put_prop", "Property size is greater then 2.");
			exit(1);
		}
	} else {
		log_Message(MFatal, "put_prop", "Tried to set nonexistant property.");
		exit(1);
	}
}
