#ifndef __DataTypes_H
#define __DataTypes_H

#include <stdint.h>

typedef uint8_t u08;
typedef int8_t s08;

typedef enum
{
    FALSE = 0,
    TRUE  = 1
} BOOL;

typedef volatile u08 * RegisterPointer;

#endif
