#include <stdlib.h>
#include "globalvars.h"

// Are we in debug mode?
unsigned int VerboseDebug = 0;

// Should we show string pointers in <>?
bool StringIndirection = 0;

// Do we trip the piracy opcode?
bool TripPiracy = 0;

// Size of the game file we are working with, in bytes.
unsigned int StorySize = 0;

// Size of the RAM the Z-Machine has.
unsigned int RAMSize = 0;

// Not quite sure...
unsigned int MaxStorySize = 0;

char* ProgramName = NULL;
