#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"

/********************************************************
 * EXT:12 C 5 / * check_unicode char-number -> (result) *
 *************************************************************************
 * Determines whether or not the interperter can print, or recieve from  *
 * the keyboard, the given Unicode character. Bit 0 should be set if and *
 * only if the interpreter can print the character, bit 1 if and only if *
 * the interpreter can receive it from the keyboard. Bits 2 to 15 are    *
 * undefined.                                                            *
 *************************************************************************/

void opCheckUnicode() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "check_unicode");
	if(g_VerboseDebug >= 25) {
		logMessage(MNull, "check_unicode", "Unicode not supported.");
	}
	// No unicode support yet.
	zStore(0);
}

