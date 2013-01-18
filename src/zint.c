#include "zint.h"

// The Z-Machine handles signed numbers as 65536-n, so the top bit is 
// basically the sign bit. This file aims to allow conversion between 
// unsigned and signed repesentations regardless of how the internal C
// casting works.

zword zSign(uzword Input) {
	if(Input <= 32767) {
		return Input;
	}
	zword Return = -1;
	while((0xFFFF+ Return + 1) != Input) {
		Return--;
	}
	return Return;
}

uzword zUnsign(zword Input) {
	if(Input >= 0)
		return Input;
	return 0xFFFF - Input + 1;
}
