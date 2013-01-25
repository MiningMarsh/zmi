#ifndef INPUT_H
#define INPUT_H 1

// Initiate the input modes of the Z-Machine and terminal.
void initInput();

// Revert the input modes of the terminal.
void cleanInput();

// Read the next pressed key from the terminal.
char readChar();

// Read a string from the terminal. Optionally parse it and execute a command to handle it.
void readString();

#endif /* input.h */
