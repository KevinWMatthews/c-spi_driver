#include "SpiPrivate.h"
#include "ATtinySpi.h"

static void hardwareSetup(void)
{
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_SLAVE, SPI_PORTA_PINS);
    ATtinySpi_EnableCounterOverflowInterrupts(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);
}

static void usiOverflowInterrupt(void)
{
    ATtinySpi_ClearCounterOverflowInterruptFlag();
    ATtinySpi_SetIsTransmittingFlag(FALSE);
    ATtinySpi_SaveInputData();
}

static void sendData(u08 data)
{
    ATtinySpi_PrepareOutputData(data);
}

void Spi_CreateSlave(void)
{
    interface.hardwareSetup = hardwareSetup;
    interface.usiOverflowInterrupt = usiOverflowInterrupt;
    interface.sendData = sendData;
}
