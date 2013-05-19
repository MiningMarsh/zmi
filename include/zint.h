/*
 * zint.h
 *
 * Xonvert between signed and unsigned formats of Z-Machine integers.
 *
 *  Created on: July 1, 2012
 *      Author: Joshua Songy
 */

#ifndef ZINT_H_
#define ZINT_H_ 1

#include <stdint.h>

// A Z-Machine word.
typedef int16_t zword;

// A Z-Machine byte.
typedef int8_t zbyte;

// An unsigned Z-Machine word.
typedef uint16_t uzword;

// An unsigned Z-Machine byte.
typedef uint8_t uzbyte;

// A Z-Machine long.
typedef int32_t zlong;

// An unsigned Z-Machine long.
typedef uint32_t uzlong;

// Convert a uzword to zword.
zword zSign(uzword Input);

// Convert a zword to uzword.
uzword zUnsign(zword Input);

#endif /* ZINT_H_ */
