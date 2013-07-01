#include <stdio.h>
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "log.h"

/*********************************
 * 2OP:22 16 mul a b -> (result) *
 *************************************************************************
 * Signed 16-bit multiplication.                                         *
 *************************************************************************/
 
void opMul() {
	zword Multiple = zSign(Operand[0]);
	zword Multiplied = zSign(Operand[1]);
	zlong Result = Multiple*Multiplied;
	static bool AlreadyWarned = false;
	if(!AlreadyWarned) {
		if(Result < -32768 || Result > 32767) {
			// Log the warning message.
			logMessage(
				MWarning, 
				"mul", 
				"%s detected. This is undefined behavior.\n"
				"Operands of %i and %i with result of %i.\n"
				"This is only reported once.",
				(char*)(Result > 32767 ? "Overflow" : "Underflow"),
				Multiple,
				Multiplied,
				Result
			);
			AlreadyWarned = true;
		}
	}
	zStore(zUnsign(Result));
}
