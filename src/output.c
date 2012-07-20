#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include "memory.h"
#include "command.h"

int w,h;
void initout() {
	w = 80;
	h = 24;

#ifdef TIOCGSIZE
	struct ttysize ts;
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	w = ts.ts_cols;
	h = ts.ts_lines;
#elif defined(TIOCGWINSZ)
	struct winsize ts;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
	w = ts.ws_col;
	h = ts.ws_row;
#endif /* TIOCGSIZE */
}
void cleanout() {
}
void print(char* str, ...) {
	if(!w)
		w=20;
	static int pos = 0;
	int strsz = 0;
	char word[1024];
	int wordsz = 0;
	while(str[strsz]) {
		switch(str[strsz]) {
			case '%': {
				char word[1024];
				int wordsz = 0;
				strsz++;
				switch(str[strsz]) {
					case 's':
						break;
					default:
						printf("Invalid expansion passed to print.\n");
				}
			break; }
			case '\n':
			case '\r':
				word[wordsz] = 0;
				printf("%s\n",word);
				wordsz = 0;
				pos = 0;
				break;
			case '\b':
				pos--;
				putchar('\b');
				break;
			case ' ':
				if(pos + wordsz > w) {
					pos = 0;
					putchar('\n');
				}
				word[wordsz] = 0;
				printf("%s ",word);
				pos += wordsz + 1;
				wordsz = 0;
				break;
			default:
				word[wordsz] = str[strsz];
				wordsz++;
				break;
		}
		strsz++;
	}
	if(wordsz) {
	if(pos + wordsz > w)
	{
		pos = 0;
		putchar('\n');
	}
	word[wordsz]=0;
	wordsz--;
	printf("%s", word);
	pos += wordsz;
	}
}
