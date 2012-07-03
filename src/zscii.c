#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "memory.h"
#include "globalvars.h"

uint32_t* getzchar(uint16_t adr) {
	uint32_t size = 1024;
	uint32_t* buffer = malloc(sizeof(uint8_t)*size);
	if(buffer == NULL) {
		fputs("No memory to get ZSCII characters.",stderr);
		exit(1);
	}
	uint32_t curchar = 1;
	buffer[0] = 0;
	uint16_t cell = 0;
	while(!(cell&32768)) {
		buffer[0] +=3;
		if(buffer[0] + 1> size) {
			size += 1024;
			buffer = realloc(buffer, sizeof(uint32_t)*size);
			if(buffer == NULL) {
				fputs("No memory to get ZSCII characters.",stderr);
				exit(1);
			}
		}
		cell = getword(adr);
		buffer[buffer[0] - 2] = (cell>>10)&31;
		buffer[buffer[0] - 1] = (cell>>5)&31;
		buffer[buffer[0]] = cell&31;
		adr += 2;
	}
	buffer = realloc(buffer,(buffer[0]+1)*sizeof(uint32_t));
	return buffer;
}

bool recurseabr = 0;
char* tozscii(uint32_t* buffer) {
	if(recurseabr > 1) {
		fputs("Nested abbreviation detected.",stderr);
		exit(1);
	}
	uint8_t lalpha = 0;
	uint8_t nalpha = 0;
	char* zscii = calloc(sizeof(char),1024);
	uint32_t ptr= 0;
	if(buffer == NULL) {
		fputs("No memory to convert ZSCII characters.",stderr);
		free(buffer);
		exit(1);
	}
	uint32_t buffc = buffer[0];
	while(buffer[0] != 0) {
		uint8_t calpha = nalpha;
		nalpha = lalpha;
		uint8_t zchar = buffer[buffc - buffer[0] + 1];
		buffer[0]--;
		switch(zchar) {
			case 0:
				zscii[ptr++] = ' ';
				break;
			case 1:
				if(Z_REV == 1) {
					zscii[ptr++] = '\n';
					break;
				}
			case 2:
				if(Z_REV < 3 && zchar == 2) {
					nalpha = (calpha + 1)%3;
					break;
				}
			case 3:
				if(Z_REV < 3 && zchar == 3) {
					nalpha = (calpha + 2)%3;
					break;
				}
				if(buffer[0]) {
					if(strindir)
						zscii[ptr++] = '<';
					uint16_t adr = 32*(zchar-1)
						+ buffer[buffc - buffer[0]-- + 1];
					adr = getword(getword(0x18) + adr*2)*2;
					recurseabr++;
					char* append = tozscii(getzchar(adr));
					int i = 0;
					while(append[i])
						zscii[ptr++] = append[i++];
					free(append);
					if(strindir)
						zscii[ptr++] = '>';
					recurseabr--;
				}
				break;
			case 4:
				if(Z_REV < 3) {
					lalpha = (calpha + 2)%3;
					nalpha = lalpha;
					break;
				}
				nalpha = 1;
				break;
			case 5:
				if(Z_REV < 3) {
					lalpha = (calpha + 2)%3;
					nalpha = lalpha;
					break;
				}
				nalpha = 2;
				break;
			default: {
				char n;
				uint16_t adr;
				adr = 0;
				if(Z_REV >= 5)
					adr = getword(0x34);
				switch(calpha) {
					case 0:
						n = 'a' + zchar-6;
						if(adr)
							n = getbyte(adr + (zchar-6));
						break;
					case 1:
						n = 'A' + zchar-6;
						if(adr)
							n = getbyte(adr + (zchar+20));
						break;
					case 2: {
						if(zchar == 6) {
							if(buffer[0] < 2) {
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
						if(zchar == 7) {
							n = '\n';
							break;
						}
						char ltable[] = {' ','\n','0','1','2','3','4',
										'5','6','7','8','9','.',
										',','!','?','_','#','\'',
										'"','/','\\','-',':','(',
										')'};
						n = ltable[zchar - 6];
						if(adr)
							n = getbyte(adr + (zchar+26 + 26 - 6));
						break; }
				}
				zscii[ptr++] = n;
				break; }
		}
	}
	free(buffer);
	zscii = realloc(zscii,ptr*sizeof(char));
	return zscii;
}
