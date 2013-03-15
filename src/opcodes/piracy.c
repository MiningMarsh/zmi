#include <stdlib.h>
#include "routine.h"
#include "globalvars.h"
#include "log.h"

/*********************************
 * 0OP:191 F 5/- piracy ?(label) *
 *************************************************************************
 * Branches if the game disc is believed to be genuine by the            *
 * interpreter (which is assumed to have some arcane way of finding      *
 * out). Interpreters are asked to be gullible and to unconditionally    *
 * branch.                                                               *
 *************************************************************************/

void opPiracy() {
	if(g_VerboseDebug >= 5 && g_TripPiracy)
		logMessage(MNull, "piracy", "Yarr, ye scurvy dog! Swab the deck!");
	zBranch(g_TripPiracy);
}
