#include <stdlib.h>
#include "log.h"
#include "zint.h"
#include "routine.h"
#include "command.h"
#include "globalvars.h"
#include "opcodes.h"
#include "output.h"

/*******************
 * 0OP:178 2 print *
 *************************************************************************
 * Print the quoted (literal) Z-encoded string.                          *
 *************************************************************************/

void opPrint() {
	if(g_VerboseDebug >= 50)
		logMessage(MNull, "CallOperation()", "print");
	// The string on this operation is stored on teh byte now pointed to
	// by the program counter.
	char* String = zGetStringFromPC();
	zPrint(String);
	
	// zPrint does not autofree.
	free(String);
}
