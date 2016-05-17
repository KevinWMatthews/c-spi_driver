#include "SpiHw.h"
#include "ATtiny.h"

void SpiHw_SetupAsSlave(void)
{
    ATtiny_SetWireMode(USI_THREE_WIRE);
    ATtiny_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    ATtiny_ConfigureUsiPins(SPI_SLAVE, SPI_PORTA_PINS);
    ATtiny_SetCounterOverflowInterrupts(TRUE);
    ATtiny_SetIsTransmittingFlag(FALSE);
}
