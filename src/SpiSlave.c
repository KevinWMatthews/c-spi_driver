#include "Spi.h"
#include "SpiPrivate.h"
#include "ATtinySpi.h"

static void hardwareSetup(void)
{
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_SLAVE, SPI_PORTA_PINS);
    ATtinySpi_EnableCounterOverflowInterrupts(TRUE);
}

static void usiOverflowInterrupt(void)
{
    ATtinySpi_ClearCounterOverflowInterruptFlag();
    ATtinySpi_SaveInputData();
}

static void sendData(u08 data)
{
    ATtinySpi_PrepareOutputData(data);
}

static s08 getData(u08 *data)
{
    *data = ATtinySpi_GetData();
    return SPI_DATA_RECEIVED;
}

void Spi_CreateSlave(void)
{
    interface.hardwareSetup = hardwareSetup;
    interface.usiOverflowInterrupt = usiOverflowInterrupt;
    interface.sendData = sendData;
    interface.getData = getData;
}

void Spi_StartConditionInterrupt(void)
{
    ATtinySpi_ClearDataRegister();
}
