#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>
#include <globalvars.h>

// Initiate the input modes of the Z-Machine and terminal.
void initin();

// Revert the input modes of the terminal.
void cleanin();

// Read the next pressed key from the terminal.
char readchar();

// Read a string from the terminal. Optionally parse it and execute a command to handle it.
void readstr();

#endif
