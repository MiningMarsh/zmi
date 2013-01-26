#include "opcodes.h"

/***********************
 * 0OP:179 3 print_ret *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string, then print a new-line    *
 * and then return true (i.e., 1).                                       *
 *************************************************************************/

void opPrintRet() {
	opPrint();
	opNewLine();
	opRtrue();
}
