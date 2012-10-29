#ifndef GLOBALVARS_H
#define GLOBALVARS_H

// Are we in debug mode?
char VerboseDebug;
#define g_VerboseDebug VerboseDebug

// Should we show string pointers in <>?
char StrIndirection;
#define g_StrIndirection StrIndirection

unsigned int g_StorySize;
unsigned int g_RAMSize;
unsigned int g_MaxStorySize;

#define d_VersionMajor 0
#define d_VersionMinor 1

#define d_StandardMajor 1
#define d_StandardMinor 0

#endif /* globalvars.h */
