#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "memory.h"
#include "zscii.h"
#include "globalvars.h"

const uint32_t default_string_size = 64;

// Return a buffer of z-characters, read from a series of compressed character packets at adr.
uint32_t* getZChars(zaddress Address)
{
	uint32_t size = default_string_size; // Default size of the string buffer is 1kb.
	uint32_t* buffer = malloc(sizeof(uint32_t)*size); // Get the string buffer.
	if(buffer == NULL)
	{ // No memory.
		fputs("No memory to get ZSCII characters.\n",stderr);
		exit(1);
	}
	buffer[0] = 0; // Size of the buffer.
	uint16_t cell = 0; // Holds the current character packet.
	while(!(cell&32768)) // Read until the end of stream flag is set in a cahracter packet.
	{
		buffer[0] +=3; // There are 3 characters per packet.
		if(buffer[0] +1 > size)
		{
			size *= 2; // Double the size of the buffer if it runs out (this plays nice with malloc).
			buffer = realloc(buffer, sizeof(uint32_t)*size);
			if(buffer == NULL)
			{ // No memory.
				fputs("No memory to get ZSCII characters.\n",stderr);
				exit(1);
			}
		}
		cell = getWord(Address); // A character packet is the size of a word.
		buffer[buffer[0] - 2] = (cell>>10)&31; // Extract the three compressed characters from the packet.
		buffer[buffer[0] - 1] = (cell>>5)&31;
		buffer[buffer[0]] = cell&31;
		Address += 2; // Advance the stream location by a word.
	}
	// Next line would save a tiny bit of memory for a few seconds, but ommiting it helps against memory fragmentation.
	/* buffer = realloc(buffer,(buffer[0]+1)*sizeof(uint32_t)); */
	return buffer;
}

char* zCharsToZSCII(uint32_t* buffer)
{
	if(buffer == NULL)
	{ // Null buffer passed.
		fputs("tried to get ASCII characters from NULL stream.\n",stderr);
		free(buffer);
		exit(1);
	}
	static bool recurseabr = 0; // The standard bans recursive string redirection, so we track it,
	if(recurseabr > 1)          // and spit an error if it is more than 1 recursion.
	{
		fputs("Nested abbreviation detected.\n",stderr);
		exit(1);
	}
	uint32_t buffc = buffer[0]; // Total size of the buffer.
	uint32_t size = default_string_size;
	while(size < buffc)
		size *= 2;
	uint8_t lalpha = 0; // Locked alpha mode.
	uint8_t nalpha = 0; // Next alpha mode.
	char* zscii = malloc(sizeof(char)*size); // Holds the converted ascii characters.
	if(zscii == NULL)
	{ // No memory.
		fputs("Not enough memory to convert zscii string.\n",stderr);
		free(buffer);
		exit(1);
	}
	uint32_t ptr= 0; // Pointer to the next free cell in the ascii buffer.
	while(buffer[0] != 0) // Loop until all the buffer had ben read.
	{
		uint8_t calpha = nalpha; // Set the current alpha to the next alpha mode in line.
		nalpha = lalpha; // Next alpha is locked alpha.
		uint8_t zchar = buffer[buffc - buffer[0] + 1]; // Get the next zcharacter to convert.
		buffer[0]--; // decrease the buffer size by one.
		if(ptr + 5 >= size) {
			size *= 2;
			zscii = realloc(zscii,sizeof(char)*size); // Holds the converted ascii characters.
			if(zscii == NULL)
			{ // No memory.
				fputs("Not enough memory to convert zscii string.\n",stderr);
				free(buffer);
				exit(1);
			}
		}
		switch(zchar)
		{
			case 0: // 0 is actually space
				zscii[ptr++] = ' ';
				break;
			case 1: // 1 is newline in version 1, in 2 it changes the shift mode.
				if(getZRev() == 1)
				{
					zscii[ptr++] = '\n';
					break;
				}
				/* no break */
			case 2: // In versions 1 and 2 this changes the shift mode.
				if(getZRev() < 3 && zchar == 2) // Needs the '&& zchar == 2' because of the missing 'break;'
				{
					nalpha = (calpha + 1)%3;
					break;
				}
				/* no break */
			case 3:
				if(getZRev() < 3 && zchar == 3) // see case 2.
				{
					nalpha = (calpha + 2)%3;
					break;
				}
				// If there is no shift to apply, we engage a string indirection.
				if(buffer[0]) // Check if
				{
					if(g_StrIndirection) // Check if we print string indirection sequences.
						zscii[ptr++] = '<';
					uint16_t adr = 32*(zchar-1)
						+ buffer[buffc - buffer[0]-- + 1];
					adr = getWord(getWord(0x18) + adr*2)*2;
					recurseabr++;
					char* append = zCharsToZSCII(getZChars(adr));
					int sz = 0;
					while(append[sz])
						sz++;
					if(ptr + 2 + sz >= size) {
						while(ptr + 2 + sz >= size)
							size *= 2;
						zscii = realloc(zscii,sizeof(char)*size); // Holds the converted ascii characters.
						if(zscii == NULL)
						{ // No memory.
							fputs("Not enough memory to convert zscii string.\n",stderr);
							free(buffer);
							exit(1);
						}
					}
					int i = 0;
					while(append[i])
						zscii[ptr++] = append[i++];
					free(append);
					if(g_StrIndirection)
						zscii[ptr++] = '>';
					recurseabr--;
				}
				break;
			case 4: // Alpha lock in version 1-2, otherwise an alpha shift.
				if(getZRev() < 3)
				{
					lalpha = (calpha + 2)%3;
					nalpha = lalpha;
					break;
				}
				nalpha = 1;
				break;
			case 5: // Alpha lock in version 1-2, otherwise an alpha shift.
				if(getZRev() < 3)
				{
					lalpha = (calpha + 2)%3;
					nalpha = lalpha;
					break;
				}
				nalpha = 2;
				break;
			default: // No special characters, now we do a standard conversion.
			{
				char n = 0;
				uint16_t adr;
				adr = 0;
				if(getZRev() >= 5)
					adr = getWord(0x34);
				switch(calpha)
				{
					case 0:
						n = 'a' + zchar-6;
						if(adr)
							n = getByte(adr + (zchar-6));
						break;
					case 1:
						n = 'A' + zchar-6;
						if(adr)
							n = getByte(adr + (zchar+20));
						break;
					case 2:
					{
						if(zchar == 6)
						{
							if(buffer[0] < 2)
							{
								buffer[0] = 0;
								n = ' ';
								break;
							}
							n= (buffer[buffc
							- buffer[0] + 1]*32)
							+ buffer[buffc - buffer[0]];
							buffer[0] -= 2;
							break;
						}
						if(zchar == 7)
						{
							n = '\n';
							break;
						}
						// There was a mathematical equation for the conversion, but it was failing miserably.
						// This lookup table does the job though, and as a plus, is character set independent! :D
						char ltable[] = {
						                 ' ','\n','0','1','2','3','4',
						                 '5','6','7','8','9','.',
						                 ',','!','?','_','#','\'',
						                 '"','/','\\','-',':','(',
						                 ')'
						                };
						n = ltable[zchar - 6];
						if(adr)
							n = getByte(adr + (zchar+26 + 26 - 6));
						break;
					}
				}
				zscii[ptr++] = n;
				break;
			}
		}
	}
	free(buffer);
	// See above.
	zscii[ptr]=0; // Null termiante the converted ascii string.
	return zscii;
}
