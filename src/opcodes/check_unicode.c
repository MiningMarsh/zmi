#include "routine.h"

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
	// No unicode support yet.
	zStore(0);
}

