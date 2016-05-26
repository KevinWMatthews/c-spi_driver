extern "C"
{
#include "ATtinySpi.h"
}

#include "CppUTestExt/MockSupport.h"

void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition)
{
    mock().actualCall("ATtinySpi_ConfigureUsiPins")
          .withParameter("masterOrSlave", masterOrSlave)
          .withParameter("pinPosition", pinPosition);
}
