#include "SpiHw.h"
#include "ATtiny.h"

void SpiHw_SetupAsSlave(void)
{
    ATtiny_SetWireMode(USI_THREE_WIRE);
    ATtiny_SetClockSource(USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
}
