#include "zint.h"
#include "routine.h"
#include "command.h"

/*************************************************
 * EXT:2 2 5 log_shift number places -> (result) *
 *************************************************************************
 * Does a logical shift of number by the given number of places,         *
 * shifting left (i.e. increasing) if places is positive, right if       *
 * negative. In a right shift, the sign is zeroed instead of being       *
 * shifted on. (See also art_shift.)                                     *
 *************************************************************************/

void opLogShift() {
	uzword Number = zSign(Operand[0]);
	zword Places = zSign(Operand[1]);
	if(Places > 0) {
		Number = Number << Places;
	} else if (Places < 0) {
		Number = Number >> (Places*(-1));
		Number = Number&0x7FFF;
	}
	zStore(zUnsign(Number));
}
