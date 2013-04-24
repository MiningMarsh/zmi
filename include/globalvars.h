#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_ 1

#include <stdbool.h>

// Are we in debug mode?
char g_VerboseDebug;

// Should we show string pointers in <>?
bool g_StrIndirection;

// Do we trip the piracy opcode?
bool g_TripPiracy;

unsigned int g_StorySize;
unsigned int g_RAMSize;
unsigned int g_MaxStorySize;

char* g_ProgramName;

#define d_VersionMajor 0
#define d_VersionMinor 6

#define d_StandardMajor 1
#define d_StandardMinor 0

#endif /* GLOBALVARS_H_ */
