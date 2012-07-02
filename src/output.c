#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "command.h"
#include "zscii.h"

uint16_t stream = 0;

void cistream(uint16_t str) {
	stream = str;
}

