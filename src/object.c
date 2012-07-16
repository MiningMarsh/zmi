#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
// Functions to manipulate the object tree.
#define objectTable getword(0x0a);
// Get the address of an object.
uint32_t getobjadr(uint16_t obj) {
	if(Z_REV < 4 && obj > 255) { // Version 3 and down only have 255 objects.
		char str[256];
		sprintf(str, "%u", obj);
		fputs("Tried to get nonexistant object ", stderr);
		fputs(str, stderr);
		fputs(".\n", stderr);
		exit(1);
	}
	uint32_t baseadr = objectTable;
	if(Z_REV > 3)
		baseadr += 63*2 + 14*(obj - 1);
	else
		baseadr += 31*2 + 9*(obj - 1);
	return baseadr;
}

// Get a flag off an object
uint16_t getobjflag(uint16_t obj, uint16_t flag) {
	uint32_t objadr = getobjadr(obj);
	uint8_t adr = getbyte(objadr+(flag/8));
	return ((adr>>(flag - (flag/8)*8))&1);
}

// Set a flag on an object.
void setobjflag(uint16_t obj, uint16_t flag, uint16_t val) {
	uint32_t objadr = getobjadr(obj);
	if(objadr != 0) {
		uint8_t adr = objadr+flag/8;
		uint8_t mask = 1<<(flag - (flag/8)*8);
		setbyte(adr, getbyte(adr)&mask);
	}
}

uint16_t getpsc(uint16_t obj, uint16_t psc) {
	uint32_t objadr = getobjadr(obj) + 4;
	if(objadr == 4)
		return 0;
	if(Z_REV > 3) {
		objadr += 2;
		return getword(objadr + 2*psc);
	} else {
		return getbyte(objadr + psc);
	}
} 

void setpsc(uint16_t obj, uint16_t val, uint16_t psc) {
	uint32_t objadr = getobjadr(obj) + 4;
	if(objadr != 4)
	if(Z_REV > 3) {
		objadr += 2;
		setword(objadr + 2*psc, val);
	} else {
		setbyte(objadr + psc,val&0xFF);
	}
}

// Set the parent of an object.
void setparent(uint16_t obj, uint16_t val) {
	setpsc(obj, val, 0);
}
void setchild(uint16_t obj, uint16_t val) {
	setpsc(obj, val, 2);
}
void setsibling(uint16_t obj, uint16_t val) {
	setpsc(obj, val, 1);
}

uint16_t getparent(uint16_t obj) {
	return getpsc(obj, 0);
}
uint16_t getchild(uint16_t obj) {
	return getpsc(obj, 2);
}
uint16_t getsibling(uint16_t obj) {
	return getpsc(obj, 1);
}

uint16_t getproptableadr(uint16_t obj){
	uint32_t adr = getobjadr(obj);
	adr += 7;
	if(Z_REV > 3)
		adr += 5;
	return getword(adr);
}

uint16_t getpropadr(uint16_t obj, uint16_t prop) {
	uint32_t adr = getproptableadr(obj);
	uint16_t size = 0;
	uint8_t hdrnamesz = getbyte(adr);
	adr += 1+2*hdrnamesz;
	if(Z_REV < 4) {
		uint8_t propn = 255;
		while(propn != prop) {
			adr += size;
			uint8_t cell = getbyte(adr);
			propn = cell&31;
			if(propn < prop) {
				propn = prop;
				adr = 0;
			}
			size = ((cell>>5)&7)+2;
		}
	} else {
	}
	return adr;
}
