#ifndef ZINT_H_
#define ZINT_H_

#include <stdint.h>

typedef int16_t zword;
typedef int8_t zbyte;

typedef uint16_t uzword;
typedef uint8_t uzbyte;

typedef int32_t zlong;
typedef uint32_t uzlong;

zword zSign(uzword Input);
uzword zUnsign(zword Input);

#endif /* zint.h */