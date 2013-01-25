#include <stdio.h>
#include "log.h"
#include "command.h"
#include "globalvars.h"

/**********************************************
 * VAR:229 5 print_char output-character-code *
 *************************************************************************
 * Print a ZSCII character. The operand must be a character code defined *
 * in ZSCII for output (see S 3). In particular, it must certainly not   *
 * be negative or larger than 1023.                                      *
 *************************************************************************/ 

void opPrintChar() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print_char");
	// TODO: Make this operation standard compliant.
	printf("%c",Operand[0]);
}
