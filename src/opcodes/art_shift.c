#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"

/***********************************************
 * 2OP:9 9 art_shift number places -> (result) *
 *************************************************************************
 * Does an arithmetic shift of _number_ by the given number of _places_, *
 * shiftin left (i.e. increasing) , right if negative. In a right shift, *
 * the sign bit is preserved as well as being shifted on down. (The      *
 * alternative behavior is 'log_shift'.)                                 *
 *************************************************************************/

void opArtShift() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "art_shift");
	// Number to shift.
	zword Number = zSign(Operand[0]);
	// Number of places to shift by.
	zword Places = zSign(Operand[1]);

	// Shift positive or negative?
	if(Places > 0) {
		// Shift left.
		Number = Number<<Places;
	} else if(Places < 0) {
		// Shift right.
		for(; Places > 0; Places--) {
			// Get the sign bit.
			int Sign = (Number>>16)&0x1;
			Number = Number>>1;
			// Restore the sign bit as well as shifting it down.
			Number = Number|(Sign<<15)|(Sign<<16);
		}
	} else {
		// Print a little warning if they shift by zero, as this
		// does nothing more than waste cpu cycles.
		static bool AlreadyReported = false;
		if(!AlreadyReported) {
			AlreadyReported = true;
			logMessage(
				MWarning, 
				"art_shift",
				"Shifting %i by 0. This is innefficient.\n"
				"This is only reported once."
			);
		}
	}
	if(g_VerboseDebug >= 25) {
		char Message[256];
		sprintf(
			Message,
			"%i %s %i -> %i",
			zSign(Operand[0]),
			Places > 0 ? "<<" : ">>",
			Places,
			Number	
		);
		logMessage(MNull, "art_shift", Message);
	}
	// Store the result.
	zStore(zUnsign(Number));
}
