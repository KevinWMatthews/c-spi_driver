#ifndef __ATtinySpiPrivate_H
#define __ATtinySpiPrivate_H

typedef void (*HardwareSetup)(void);

typedef struct ATtinySpiInterface
{
    HardwareSetup hardwareSetup;
} ATtinySpiInterface;

#endif
