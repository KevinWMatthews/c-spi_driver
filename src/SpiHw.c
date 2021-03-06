#include "SpiHw.h"
#include "ATtinySpi.h"
#include "ATtinyTimer0.h"

void SpiHw_SetupAsSlave(void)
{
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_SLAVE, SPI_PORTA_PINS);
    ATtinySpi_SetCounterOverflowInterrupts(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);
}

void SpiHw_SetupAsMaster(void)
{
    // Set up ATtinySpi parameters
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTA_PINS);
    ATtinySpi_SetCounterOverflowInterrupts(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);

    // Set up ATtinyTimer0 parameters
    ATtinyTimer0_SetTimerBitWidth(T0_EIGHT_BIT);
    ATtinyTimer0_ClearTimerOnMatch(TRUE);
    ATtinyTimer0_SetPrescaleFactor(T0_PRESCALE_FACTOR_64);
    ATtinyTimer0_SetTimerCompareValue0A(125);
    ATtinyTimer0_SetTimerCompareInterrupt0A(FALSE);
}
