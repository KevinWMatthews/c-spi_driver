extern "C"
{
#include "ATtinySpi.h"
}

#include "CppUTestExt/MockSupport.h"

void ATtinySpi_SetWireMode(Usi_WireMode wireMode)
{
    mock().actualCall("ATtinySpi_SetWireMode")
          .withParameter("wireMode", wireMode);
}

void ATtinySpi_SetClockSource(Usi_ClockSource clockSource)
{
    mock().actualCall("ATtinySpi_SetClockSource")
          .withParameter("clockSource", clockSource);
}

void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition)
{
    mock().actualCall("ATtinySpi_ConfigureUsiPins")
          .withParameter("masterOrSlave", masterOrSlave)
          .withParameter("pinPosition", pinPosition);
}

void ATtinySpi_SetCounterOverflowInterrupts(BOOL enableInterrupts)
{
    mock().actualCall("ATtinySpi_SetCounterOverflowInterrupts")
          .withParameter("enableInterrupts", enableInterrupts);
}

void ATtinySpi_SetIsTransmittingFlag(BOOL isTransmitting)
{
    mock().actualCall("ATtinySpi_SetIsTransmittingFlag")
          .withParameter("isTransmitting", isTransmitting);
}
