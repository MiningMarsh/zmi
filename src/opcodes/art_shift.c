#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"

/***********************************************
 * 2OP:9 9 art_shift number places -> (result) *
 *************************************************************************
 * Does an arithmetic shift of _number_ by the given number of _places_, *
 * shifting left (i.e. increasing), right if negative. In a right shift, *
 * the sign bit is preserved as well as being shifted on down. (The      *
 * alternative behavior is 'loshift'.)                                 *
 *************************************************************************/

void opArtShift() {
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
		for(; Places < 0; Places++) {
			// Get the sign bit.
			unsigned int Sign = (Number>>15)&0x1;
			Number = Number>>1;
			// Restore the sign bit.
			Number = Number|(Sign<<15);
		}
	}
	// Store the result.
	zStore(zUnsign(Number));
}
