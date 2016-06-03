#include "Spi.h"
#include "SpiPrivate.h"

SpiInterface interface;

void Spi_HwSetup(void)
{
    interface.hardwareSetup();
}

void Spi_UsiOverflowInterrupt(void)
{
    interface.usiOverflowInterrupt();
}
