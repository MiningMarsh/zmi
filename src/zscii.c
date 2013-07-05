#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "zint.h"
#include "memory.h"
#include "zscii.h"
#include "globalvars.h"
#include "log.h"

const uint32_t DefaultStringSize = 64;

// Return a buffer of z-characters, read from a series of compressed character packets at Address.
uint32_t* getZChars(zaddress Address) {

	uint32_t BufferSize = DefaultStringSize;
	
	// Allocate a buffer to hold the string.
	uint32_t* Buffer = malloc(sizeof(uint32_t) * BufferSize);
	if(Buffer == NULL) {
		// No memory.
		logMessage(MFatal, "getZChars", "No memory to get ZSCII characters.\n");
		exit(1);
	}
	
	// Stores how many characters have been read into the buffer.
	Buffer[0] = 0;
	
	// Holds the current character packet.
	uzword Cell = 0;
	
	// Keep reading packets until we hit an end of stream flag.
	while(!(Cell&32768)) {
		
		// There are 3 characters per packet.
		Buffer[0] += 3;
		
		if(Buffer[0] +1 > BufferSize) {
			BufferSize *= 2; // Double the size of the buffer if it runs out (this plays nice with malloc).
			Buffer = realloc(Buffer, sizeof(uint32_t) * BufferSize);
			if(Buffer == NULL) {
				// No memory.
				logMessage(MFatal, "getZChars", "No memory to get ZSCII characters.\n");
				free(Buffer);
				exit(1);
			}
		}
		
		Cell = getWord(Address); // A character packet is the size of a word.
		
		Buffer[Buffer[0] - 2] = (Cell>>10)&31; // Extract the three compressed characters from the packet.
		Buffer[Buffer[0] - 1] = (Cell>>5)&31;
		Buffer[Buffer[0]] = Cell&31;
		
		Address += 2; // Advance the stream location by a word.
	}
	// We could resize the buffer to optimal size, buts lets avoid a possible 
	// reallocation failure and avoid extra fragmentation.
	return Buffer;
}

// I am truly sorry to anyone reading through this function, I should get 
// lynched for how crap this is. But it does work. I think. Trust me on this.
char* zCharsToZSCII(uint32_t* Buffer) {

	if(Buffer == NULL) {
		// Null buffer passed.
		logMessage(MFatal, "zCharsToZSCII", "Tried to convert NULL buffer into ZSCII.\n");
		exit(1);
	}
	
	// Recursive string indirection is banned, detect it here.
	static unsigned int Recursion = 0;
	if(Recursion > 1) {
		logMessage(MFatal, "zCharsToZSCII", "Nested abbreviation detected.\n");
		exit(1);
	}
	
	// BufferCount holds how many characters are in the buffer.
	uint32_t BufferCount = Buffer[0];
	
	// Allocate a new character buffer to hold the ascii characters, but make 
	// it a power of two to help stop fragmentation.
	uint32_t BufferSize = DefaultStringSize;
	while(BufferSize < BufferCount) {
		BufferSize *= 2;
	}
	
	// Are we in locked alpha mode?
	unsigned char LockedAlpha = 0; // Locked alpha mode.
	// What us the next alpha mode?
	unsigned char NextAlpha = 0; // Next alpha mode.
	
	char* Zscii = malloc(sizeof(char) * BufferSize); // Holds the converted ascii characters.
	if(Zscii == NULL) {
		// No memory.
		logMessage(MFatal, "zCharsToZSCII", "Ran out of memory.\n");
		free(Buffer);
		exit(1);
	}
	
	// Index into the Zscii buffer.
	unsigned long long int Index = 0;
	
	// Loop until the source buffer is empty.
	while(Buffer[0]) {
		
		// Advance the alpha mode
		unsigned char CurrentAlpha = NextAlpha;
		// By default the next alpha mode is locked.
		NextAlpha = LockedAlpha; 

		// Get the next character to convert.
		char ZChar = Buffer[BufferCount - Buffer[0] + 1];

		// We just handled one character in the buffer.
		--Buffer[0];
		
		// TODO: Figure out this magic number 5.
		if(Index + 5 >= BufferSize) {
			BufferSize *= 2;
			
			// Holds the converted ascii characters.
			Zscii = realloc(Zscii, sizeof(char) * BufferSize); 
			if(Zscii == NULL) {
				// No memory.
				logMessage(MFatal, "zCharsToZSCII", "Ran out of memory.\n");
				free(Buffer);
				free(Zscii);
				exit(1);
			}
		}

		// Convert the character.

		// TODO: Figure out what the fuck I was talking about with 1, 2, and 3 
		// shifting. I see no such code logic.
		switch(ZChar) {
			// 0 is space.
			case 0:
				Zscii[Index++] = ' ';
				break;
			
			// 1 is newline in revision 1, else it changes shift mode.
			case 1:
				if(getZRev() == 1) {
					Zscii[Index++] = '\n';
					break;
				}
				// No break is on purpose, case 2 also shifts mode, so we handle both at 
				// once.
			
			// In versions 1 and 2 this changes the shift mode.
			case 2: 
				// Needs the '&& zchar == 2' because of the missing 'break;'
				if(getZRev() <= 2 && ZChar == 2) {
					// Math to shift alpha mode. Modes wrap from 0..1..2..0 etc. This 
					// increases shift mode by 1.
					NextAlpha = (CurrentAlpha + 1)%3;
					break;
				}
				// No break is on purpose, case 3 also shifts mode, so we handle both at 
				// once.
				
			case 3:
				// see case 2.
				if(getZRev() <= 2 && ZChar == 3) {
					// Same as before but we increase case mode by 2.
					NextAlpha = (CurrentAlpha + 2)%3;
					break;
				}
				
				// In other versions this is string indirection, because they finally got sane.
				if(Buffer[0]) {
					
					// Check if we print <> around string indirection sequences.
					if(StringIndirection) {
						Zscii[Index++] = '<';
					}
					
					// TODO: I don't even?
					zaddress Address = 32*(ZChar-1) + Buffer[BufferCount - Buffer[0]-- + 1];


					Address = getWord(getWord(0x18) + Address*2)*2;
					
					// Increase recursion count.
					++Recursion;
					
					// Character buffer holding the indirected string, that we are going to append.
					char* Append = zCharsToZSCII(getZChars(Address));
					
					int IndirectedBufferSize = 0;
					while(Append[IndirectedBufferSize]) {
						IndirectedBufferSize++;
					}

					if(Index + 2 + IndirectedBufferSize >= BufferSize) {
						
						while(Index + 2 + IndirectedBufferSize >= BufferSize) {
							BufferSize *= 2;
						}

						Zscii = realloc(Zscii, sizeof(char) * BufferSize); 
						// Check for out of memory.
						if(Zscii == NULL) {
							logMessage(MFatal, "zCharsToZSCII", "Ran out of memory.\n");
							free(Buffer);
							free(Zscii);
							exit(1);
						}
					}
					
					// Basically strcpy.
					unsigned long long int AppendIndex = 0;
					while(Append[AppendIndex]) {
						Zscii[Index++] = Append[AppendIndex++];
					}
					
					// We are done with the new buffer.
					free(Append);
					
					if(StringIndirection) {
						Zscii[Index++] = '>';
					}
					
					// Decrease recursion count.
					Recursion--;
				}
				break;
			
			// Alpha lock in version 1-2, otherwise an alpha shift.
			case 4: 
				if(getZRev() <= 2) {
					LockedAlpha = (CurrentAlpha + 2)%3;
					NextAlpha = LockedAlpha;
					break;
				}
				NextAlpha = 1;
				break;
			
			// Alpha lock in version 1-2, otherwise an alpha shift.
			case 5: 
				if(getZRev() <= 2)
				{
					LockedAlpha = (CurrentAlpha + 2)%3;
					NextAlpha = LockedAlpha;
					break;
				}
				NextAlpha = 2;
				break;
			
			// No special characters, now we do a standard conversion.
			default: {
				char Next = 0;
				
				// Get an alternate char table if it exists. 
				zaddress Address = 0;
				if(getZRev() >= 5) {
					Address = getWord(0x34);
				}
				
				// OH NOES NESTED SWITCH. /me dies.
				switch(CurrentAlpha) {
					// It is a lower case character.
					case 0:
						Next = 'a' + ZChar-6;
						if(Address) {
							Next = getByte(Address + (ZChar-6));
						}
						break;

					// It is an uppercase character.
					case 1:
						Next = 'A' + ZChar-6;
						if(Address)
							Next = getByte(Address + (ZChar+20));
						break;

					// Else... I don't fucking know anymore, man!
					case 2: {
						if(ZChar == 6) {
							if(Buffer[0] < 2) {
								Buffer[0] = 0;
								Next = ' ';
								break;
							}
							// What the fuck?
							Next = (Buffer[BufferCount
							- Buffer[0] + 1]*32)
							+ Buffer[BufferCount - Buffer[0]];
							Buffer[0] -= 2;
							break;
						}
						
						// 7 is newline.
						if(ZChar == 7) {
							Next = '\n';
							break;
						}

						// There was a mathematical equation for the conversion, but it was failing miserably.
						// This lookup table does the job though, and as a plus, is character set independent! :D
						char CharacterTable[] = {
						                 ' ','\n','0','1','2','3','4',
						                 '5','6','7','8','9','.',
						                 ',','!','?','_','#','\'',
						                 '"','/','\\','-',':','(',
						                 ')'
						                };
						Next = CharacterTable[ZChar - 6];
						if(Address) {
							Next = getByte(Address + (ZChar+26 + 26 - 6));
						}
						break;
					}
				}
				
				// Set next cell in the buffer to the converted character.
				Zscii[Index++] = Next;
				break;
			}
		}
	}
	// We are done with the source buffer.
	free(Buffer);
	// Null termiante the converted ascii string.
	Zscii[Index] = 0; 
	return Zscii;
}
