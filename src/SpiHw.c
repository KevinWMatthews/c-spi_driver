#include "SpiHw.h"
#include "ATtinySpi.h"

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
    ATtinySpi_SetWireMode(USI_THREE_WIRE);
    ATtinySpi_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTA_PINS);
    ATtinySpi_SetCounterOverflowInterrupts(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);
}
