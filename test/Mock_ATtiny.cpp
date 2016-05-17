extern "C"
{
#include "ATtiny.h"
}

#include "CppUTestExt/MockSupport.h"

void ATtiny_SetWireMode(Usi_WireMode wireMode)
{
    mock().actualCall("ATtiny_SetWireMode")
          .withParameter("wireMode", wireMode);
}

void ATtiny_SetClockSource(Usi_ClockSource clockSource)
{
    mock().actualCall("ATtiny_SetClockSource")
          .withParameter("clockSource", clockSource);
}
