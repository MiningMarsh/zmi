#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "zint.h"
#include "routine.h"
#include "command.h"

/**************************************
 * VAR:231 7 random range -> (result) *
 *************************************************************************
 * If range is positive, returns a uniformly random number between 1 and *
 * range. If range is negative, the random number generator is seeded to *
 * that value and the return value is 0. Most interpreters consider      *
 * giving 0 as range illegal (because they attempt a division with       *
 * remainder by the range), but correct behaviour is to reseed the       *
 * generator in as random a way as the interpreter can(e.g. by using the *
 * time in milliseconds). (Some version 3 games, such as 'Enchanter'     *
 * release 29, had a debugging verb #random such that typing, say,       *
 * #random 14 caused a call of random with -14.)                         *
 *************************************************************************/

void opRandom() {

	zword Seed = zSign(Operand[0]);

	// This state varibale represents the current value of the LFSR. 
	// Since in normal operation, a LFSR will never reach state 0, we
	// can assume a value of 0 means we have not yet initilized the LFSR.
	static uint64_t State = 0;
	// Set the inital random value to the current clock.
	while(!State)
		State = time(NULL)%0xFFFF - clock();
	bool Next;
	for(unsigned int I = 0; I < 64; I++) {
		Next = 1&((State>>63)^(State>>62)^(State>>60)^(State>>59));
		State = ((State<<1)) | (Next);
	}
	if(Seed > 0) {
		zStore(State%Seed);
	} else if(Seed < 0) {
		zStore(0);
		State = Seed;
	} else {
		zStore(0);
		State = time(NULL)%0xFFFF;
	}
}

