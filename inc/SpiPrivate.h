#ifndef __SpiPrivate_H
#define __SpiPrivate_H

#include "DataTypes.h"

typedef void (*HardwareSetup)(void);
typedef void (*UsiOverflowInterrupt)(void);
typedef void (*SendData)(u08);
typedef s08 (*GetData)(u08 *data);

typedef struct SpiInterface
{
    HardwareSetup hardwareSetup;
    UsiOverflowInterrupt usiOverflowInterrupt;
    SendData sendData;
    GetData getData;
} SpiInterface;

extern SpiInterface interface;

#endif
