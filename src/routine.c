#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "memory.h"
#include "command.h"
#include "zscii.h"

void store(uint16_t value) {
	setZVar(getByte(current_frame->PC++),value);
}

char* getstring() {
	uint32_t* buffer = getzchar(current_frame->PC);
	current_frame->PC += (buffer[0]/3)*2;
	return tozscii(buffer);
}

void branch(bool condition) {
	uint8_t bdat = getByte(current_frame->PC++);
	uint16_t offset = bdat&63;
	if((bdat&64) != 64)
		offset = (offset<<8)+getByte(current_frame->PC++);
	if(condition ^ (!((bdat>>7)&1))) {
		if(offset > 1) {
			current_frame->PC += (offset > 8191 ? offset - 16384 : offset) - 2;
		} else {
			popZFrame();
			if(current_frame->retvar == 1)
				setZVar(getByte(current_frame->PC++), offset);
			current_frame->retvar = 1;
		}
	}
}
