#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
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
void print() {
	static int pos = 0;
}
