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

void ATtiny_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition)
{
    mock().actualCall("ATtiny_ConfigureUsiPins")
          .withParameter("masterOrSlave", masterOrSlave)
          .withParameter("pinPosition", pinPosition);
}

void ATtiny_SetCounterOverflowInterrupts(BOOL enableInterrupts)
{
    mock().actualCall("ATtiny_SetCounterOverflowInterrupts")
          .withParameter("enableInterrupts", enableInterrupts);
}

void ATtiny_SetIsTransmittingFlag(BOOL isTransmitting)
{
    mock().actualCall("ATtiny_SetIsTransmittingFlag")
          .withParameter("isTransmitting", isTransmitting);
}
