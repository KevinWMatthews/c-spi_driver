#ifndef __SpiPrivate_H
#define __SpiPrivate_H

typedef void (*HardwareSetup)(void);
typedef void (*UsiOverflowInterrupt)(void);

typedef struct SpiInterface
{
    HardwareSetup hardwareSetup;
    UsiOverflowInterrupt usiOverflowInterrupt;
} SpiInterface;

extern SpiInterface interface;

#endif
