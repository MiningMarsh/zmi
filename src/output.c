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
	static int pos = 0;
	int strsz = 0;
	int length = strlen(str);
	char word[1024];
	int wordsz = 0;
	while(strsz<length) {
		switch(str[strsz]) {
			case '%':
			break;
			case '\n':
			case '\r':
				pos = 0;
				putchar(str[strsz]);
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
				pos += wordsz;
				wordsz = 0;
				break;
			default:
				word[wordsz] = str[strsz];
				wordsz++;
				break;
		}
		strsz++;
	}
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
