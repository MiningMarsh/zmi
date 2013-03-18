#include <stdio.h>
#include <stdbool.h>
#include "memory.h"
#include "zscii.h"
#include "globalvars.h"
#include "log.h"

// Store commands use the next byte as the variable to store into.
// all store commans execute this to store things.
void zStore(uzword Value) {
	uzbyte Variable = getByte(CurrentZFrame->PC++);
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
	uzbyte BranchData = getByte(CurrentZFrame->PC++);

	// The jump offset is the lower 5 bits.
	uzword Offset = BranchData&63;
	if(g_VerboseDebug >= 40) {
		char Message[256];
		sprintf(
			Message,
			"Condition passed is %u.\n"
			"Success condition is %u.\n"
			"Branch offset is %i.",
			Condition,
			(BranchData>>7)&1,
			zSign(Offset)
		);
		logMessage(MNull, "zBranch()", Message);
	}
	// The next byte in the stream could be appended to the jump offset.
	if(!((BranchData>>6)& 1)) {
		Offset = (Offset<<8)+(getByte(CurrentZFrame->PC++));
		if(g_VerboseDebug >= 40) {
			char Message[256];
			sprintf(
				Message,
				"Extended branch offset is %i.",
				zSign(Offset)
			);
			logMessage(MNull, "zBranch()", Message);
		}
	}

	// The seventh bit is used to tell if we jump on true or false.
	if(Condition ^ (!((BranchData>>7)&1))) {
		if(Offset > 1) {
			CurrentZFrame->PC += zSign(Offset) - 2;
			if(g_VerboseDebug >= 40)
				logMessage(MNull, "zBranch()", "Jumping by offset.");

		// We are returning instead of jumping.
		} else {
			popZFrame();
			if(CurrentZFrame->ReturnVar == 1)
				setZVar(getByte(CurrentZFrame->PC++), Offset);
			CurrentZFrame->ReturnVar = 1;
			if(g_VerboseDebug >= 40)
				logMessage(MNull, "zBranch()", "Returning offset.");
		}
	} else {
		if(g_VerboseDebug >= 40)
			logMessage(MNull, "zBranch()", "Not jumping.");
	}
}
