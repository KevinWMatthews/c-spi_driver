#include "Spi.h"
#include "SpiPrivate.h"

SpiInterface interface;

void Spi_HwSetup(void)
{
    if (interface.hardwareSetup == NULL)
        return;

    interface.hardwareSetup();
}

void Spi_UsiOverflowInterrupt(void)
{
    if (interface.usiOverflowInterrupt == NULL)
        return;

    interface.usiOverflowInterrupt();
}

void Spi_SendData(u08 data)
{
    if (interface.sendData == NULL)
        return;

    interface.sendData(data);
}

s08 Spi_GetData(u08 *data)
{
    if (interface.getData == NULL)
        return;

    return interface.getData(data);
}
