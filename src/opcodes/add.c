#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"

/*********************************
 * 2OP:20 14 add a b -> (result) *
 *************************************************************************
 * Signed 16-bit addition.                                               *
 *************************************************************************/

void opAdd() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "add");
	// The first number to add, casted from its unsigned form in memory.
	zword Number1 = zSign(Operand[0]);
	// The second number to add, casted from its unsigned form in memory.
	zword Number2 = zSign(Operand[1]);
	// Result, 32bit to check for over/underflows which are undefined 
	// behavior that is commonly defined as modulo 10000.
	zlong Result = (zlong)(Number1 + Number2);
	// Did we over/underflow?
	static bool AlreadyWarned = false;
	if(!AlreadyWarned)
		if(Result < -32768 || Result > 32767) {
			// Log the warning message.
			char Message[256];
			sprintf(
				Message,
				"%s detected. This is undefined behavior.\n"
				"Operands of %i and %i with result of %i.\n"
				"This is only reported once.",
				(char*)(Number1 > 32767 ? "Overflow" : "Underflow"),
				Number1,
				Number2,
				Result
			);
			logMessage(MWarning, "add", Message);
			AlreadyWarned = true;
		}
	// Store the result.
	zStore(zUnsign((Number1 + Number2)));
}
