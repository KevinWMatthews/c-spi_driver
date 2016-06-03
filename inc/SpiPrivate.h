#ifndef __SpiPrivate_H
#define __SpiPrivate_H

typedef void (*HardwareSetup)(void);

typedef struct SpiInterface
{
    HardwareSetup hardwareSetup;
} SpiInterface;

extern SpiInterface interface;

#endif
