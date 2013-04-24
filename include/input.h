#ifndef INPUT_H_
#define INPUT_H_ 1

// Initiate the input modes of the Z-Machine and terminal.
void initInput();

// Revert the input modes of the terminal.
void cleanInput();

// Read the next pressed key from the terminal.
char readChar();

// Read a string from the terminal. Optionally parse it and execute a command to handle it.
void readString();

#endif /* INPUT_H_ */
