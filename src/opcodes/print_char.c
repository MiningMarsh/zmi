#include <stdio.h>
#include "command.h"
#include "output.h"

/**********************************************
 * VAR:229 5 print_char output-character-code *
 *************************************************************************
 * Print a ZSCII character. The operand must be a character code defined *
 * in ZSCII for output (see S 3). In particular, it must certainly not   *
 * be negative or larger than 1023.                                      *
 *************************************************************************/ 

void opPrintChar() {
	// TODO: Make this operation standard compliant.
	char Buffer[2];
	Buffer[0] = Operand[0];
	Buffer[1] = 0;
	zPrint(Buffer);
}
