#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "memory.h"
#include "command.h"
#include "zscii.h"

// Store commands use the next byte as the variable to store into.
// all store commans execute this to store things.
void zStore(uint16_t value) {
	setZVar(getByte(CurrentZFrame->PC++),value);
}

// Grab a string from the PC stream.
char* zGetStringFromPC() {
	uint32_t* buffer = getZChars(CurrentZFrame->PC);
	CurrentZFrame->PC += (buffer[0]/3)*2;
	return zCharsToZSCII(buffer);
}

void zBranch(bool condition) {
	uint8_t bdat = getByte(CurrentZFrame->PC++);
	uint16_t offset = bdat&63;
	if((bdat&64) != 64)
		offset = (offset<<8)+getByte(CurrentZFrame->PC++);
	if(condition ^ (!((bdat>>7)&1))) {
		if(offset > 1) {
			CurrentZFrame->PC += (offset>8191?offset-16384:offset) - 2;
		} else {
			popZFrame();
			if(CurrentZFrame->ReturnVar == 1)
				setZVar(getByte(CurrentZFrame->PC++), offset);
			CurrentZFrame->ReturnVar = 1;
		}
	}
}
