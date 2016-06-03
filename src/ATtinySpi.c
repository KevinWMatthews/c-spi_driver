#include "ATtinySpi.h"
#include <avr/io.h>
#include "BitManip.h"

static BOOL isTransmittingFlag = FALSE;

void ATtinySpi_SetWireMode(Usi_WireMode wireMode)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, wireMode, BITMASK_SPI_WIRE_MODE);
}

void ATtinySpi_SetClockSource(Usi_ClockSource clockSource)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, clockSource, BITMASK_SPI_CLOCK_SOURCE);
}

void ATtinySpi_SetCounterOverflowInterrupts(BOOL enableInterrupts)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, enableInterrupts, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);
}

void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition)
{
    //TODO
}

void ATtinySpi_SetIsTransmittingFlag(BOOL isTransmitting)
{
    isTransmittingFlag = isTransmitting;
}

BOOL ATtinySpi_GetIsTransmittingFlag(void)
{
    return isTransmittingFlag;
}
