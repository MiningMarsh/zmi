#include "zint.h"

// The Z-Machine handles signed numbers as 65536-n, so the top bit is 
// basically the sign bit. This file aims to allow conversion between 
// unsigned and signed repesentations regardless of how the internal C
// casting works.

zword zSign(uzword Input) {
	if(Input <= 32767) {
		return Input;
	}
	return -(0xFFFF - Input + 1);
}

uzword zUnsign(zword Input) {
	if(Input >= 0)
		return Input;
	return 0xFFFF - Input + 1;
}
