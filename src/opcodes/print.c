#include "stdlib.h"
#include "routine.h"
#include "output.h"

/*******************
 * 0OP:178 2 print *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string.                          *
 *************************************************************************/

void opPrint() {
	// The string on this operation is stored on teh byte now pointed to
	// by the program counter.
	char* String = zGetStringFromPC();
	zPrint(String);
	
	// zPrint does not autofree.
	free(String);
}
