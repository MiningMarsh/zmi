#include <stdlib.h>
#include "globalvars.h"

// Are we in debug mode?
char g_VerboseDebug = 0;

// Should we show string pointers in <>?
bool g_StrIndirection = 0;

// Do we trip the piracy opcode?
bool g_TripPiracy = 0;

// Size of the game file we are working with, in bytes.
unsigned int g_StorySize = 0;

// Size of the RAM the Z-Machine has.
unsigned int g_RAMSize = 0;

// Not quite sure...
unsigned int g_MaxStorySize = 0;

char* g_ProgramName = NULL;
