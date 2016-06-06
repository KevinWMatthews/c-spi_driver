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

void ATtinySpi_EnableCounterOverflowInterrupts(BOOL enableInterrupts)
{
    mock().actualCall("ATtinySpi_EnableCounterOverflowInterrupts")
          .withParameter("enableInterrupts", enableInterrupts);
}

void ATtinySpi_SetIsTransmittingFlag(BOOL isTransmitting)
{
    mock().actualCall("ATtinySpi_SetIsTransmittingFlag")
          .withParameter("isTransmitting", isTransmitting);
}

void ATtinySpi_ClearCounterOverflowInterruptFlag(void)
{
    mock().actualCall("ATtinySpi_ClearCounterOverflowInterruptFlag");
}

void ATtinySpi_PrepareOutputData(u08 data)
{
    mock().actualCall("ATtinySpi_PrepareOutputData")
        .withParameter("data", data);
}

void ATtinySpi_SaveInputData(void)
{
    mock().actualCall("ATtinySpi_SaveInputData");
}

void ATtinySpi_ToggleUsiClock(void)
{
    mock().actualCall("ATtinySpi_ToggleUsiClock");
}

u08 ATtinySpi_GetData(void)
{
    mock().actualCall("ATtinySpi_GetData");
    return mock().intReturnValue();
}

BOOL ATtinySpi_IsTransmitting(void)
{
    mock().actualCall("ATtinySpi_IsTransmitting");
    return (BOOL)( mock().intReturnValue() );
}

void ATtinySpi_SelectSlave(void)
{
    mock().actualCall("ATtinySpi_SelectSlave");
}
