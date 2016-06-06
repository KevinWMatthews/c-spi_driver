#include "SpiMaster.h"
#include "SpiPrivate.h"
#include "ATtinySpi.h"
#include "ATtinyTimer0.h"

static void hardwareSetup(void)
{
    // Set up ATtinySpi parameters
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTA_PINS);
    ATtinySpi_EnableCounterOverflowInterrupts(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);

    // Set up ATtinyTimer0 parameters
    ATtinyTimer0_SetTimerBitWidth(T0_EIGHT_BIT);
    ATtinyTimer0_ClearTimerOnMatch(TRUE);
    ATtinyTimer0_SetPrescaleFactor(T0_PRESCALE_FACTOR_64);
    ATtinyTimer0_SetTimerCompareValue0A(125);
    ATtinyTimer0_EnableTimerCompareInterrupt0A(FALSE);
}

static void usiOverflowInterrupt(void)
{
    ATtinyTimer0_EnableTimerCompareInterrupt0A(FALSE);
    ATtinySpi_ClearCounterOverflowInterruptFlag();
    ATtinySpi_SetIsTransmittingFlag(FALSE);
    ATtinySpi_SaveInputData();
}

static void sendData(u08 data)
{
    ATtinySpi_PrepareOutputData(data);
    ATtinyTimer0_EnableTimerCompareInterrupt0A(TRUE);
}

s08 getData(u08 *data)
{
    if (ATtinySpi_IsTransmitting() == TRUE)
        return SPI_TRANSMISSION_IN_PROGRESS;

    *data = ATtinySpi_GetData();
    return SPI_DATA_RECEIVED;
}

void Spi_CreateMaster(void)
{
    interface.hardwareSetup = hardwareSetup;
    interface.usiOverflowInterrupt = usiOverflowInterrupt;
    interface.sendData = sendData;
    interface.getData = getData;
}

void SpiMaster_ClockInterrupt(void)
{
    ATtinySpi_ToggleUsiClock();
}
