#ifndef ZINT_H_
#define ZINT_H_

#include <stdint.h>

typedef int16_t zword;
typedef char zbyte;

typedef uint16_t uzword;
typedef unsigned char uzbyte;

typedef int32_t zlong;
typedef uint32_t uzlong;

zword zSign(uzword Input);
uzword zUnsign(zword Input);

#endif /* zint.h */
