#include "zint.h"

// The Z-Machine handles signed numbers as 65536-n, so the top bit is 
// basically the sign bit. This file aims to allow conversion between 
// unsigned and signed repesentations regardless of how the internal C
// casting works.

zword zSign(uzword Input) {
	return zSignBase(Input, 16);
}

uzword zUnsign(zword Input) {
	return zUnsignBase(Input, 16);
}

zword zSignBase(uzword Input, unsigned int Base) {
	uzword Converter = 1;
	uzword Limit = (1<<(Base-1));
	while(--Base) {
		Converter = (Converter<<1)|1;
	}
	if(Input&Limit)
		return -(Converter - Input + 1);
	return Input;
}

uzword zUnsignBase(zword Input, unsigned int Base) {
	uzword Converter = 1;
	while(--Base) {
		Converter = (Converter<<1)|1;
	}
	if(Input >= 0)
		return Input;
	return Converter - Input + 1;
}

