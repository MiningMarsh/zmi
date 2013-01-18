#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "memory.h"
#include "command.h"
#include "zscii.h"
#include "globalvars.h"
#include "log.h"

// Store commands use the next byte as the variable to store into.
// all store commans execute this to store things.
void zStore(uint16_t Value) {
	uint8_t Variable = getByte(CurrentZFrame->PC++);
	if(g_VerboseDebug >= 20) {
		char Message[256];
		sprintf(
			Message,
			"Storing %u into var %u.",
			Value,
			Variable
		);
		logMessage(MNull, "zStore()", Message);
	}
	setZVar(Variable, Value);
}

// Grab a string from the PC stream.
char* zGetStringFromPC() {
	// Grab thr raw zcharacters.
	uint32_t* Buffer = getZChars(CurrentZFrame->PC);
	// Increase the pc by the buffersize.
	CurrentZFrame->PC += (Buffer[0]/3)*2;
	// Convert the buffer into ascii.
	return zCharsToZSCII(Buffer);
}

void zBranch(bool Condition) {
	// Grab the byte of branch data.
	uint8_t BranchData = getByte(CurrentZFrame->PC++);

	// The jump offset are the lower 5 bits.
	uint16_t Offset = BranchData&63;

	// The nxt byte in the stream could be appended to the jump offset.
	if(BranchData>>5 & 1)
		Offset = (Offset<<8)+getByte(CurrentZFrame->PC++);

	// The eigth bit is used to tell if we jump on true or false.
	if(Condition ^ (!((BranchData>>7)&1))) {

		if(Offset > 1) {
			CurrentZFrame->PC += (Offset>8191 ? Offset-16384:Offset) - 2;

		// We are returning instead of jumping.
		} else {
			popZFrame();
			if(CurrentZFrame->ReturnVar == 1)
				setZVar(getByte(CurrentZFrame->PC++), Offset);
			CurrentZFrame->ReturnVar = 1;
		}
	}
}
