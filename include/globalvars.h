/*
 * globalvars.h
 *
 * Global variables.
 *
 *  Created on: July 1, 2012
 *      Author: Joshua Songy
 */

#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_ 1

#include <stdbool.h>

// Are we in debug mode?
extern unsigned int VerboseDebug;

// Should we show string pointers in <>?
extern bool StringIndirection;

// Do we trip the piracy opcode?
extern bool TripPiracy;

// Size of the game file we are working with, in bytes.
extern unsigned int StorySize;

// Size of the RAM the Z-Machine has.
extern unsigned int RAMSize;

// Not quite sure...
extern unsigned int MaxStorySize;

extern char* ProgramName;

#define d_VersionMajor 0
#define d_VersionMinor 7

#define d_StandardMajor 1
#define d_StandardMinor 0

#endif /* GLOBALVARS_H_ */
