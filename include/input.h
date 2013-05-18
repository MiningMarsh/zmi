/*
 * input.h
 *
 * The functions in this header are used to display output.
 *
 *  Created on: July 1, 2012
 *      Author: Joshua Songy
 */

#ifndef INPUT_H_
#define INPUT_H_ 1

// Initiate the input modes of the Z-Machine and the host OS.
void initInput();

// Revert the input modes of the host OS.
void cleanInput();

// Read the next pressed key from the OS.
char readChar();

// Read a string from the OS.
void readString();

#endif /* INPUT_H_ */
