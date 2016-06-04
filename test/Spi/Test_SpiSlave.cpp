extern "C"
{
#include "SpiSlave.h"
#include "ATtinySpi.h"
#include "ATtinyTimer0.h"
}

#include "Test_SpiSlave.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(SpiSlave)
{
    void setup()
    {
        mock().strictOrder();
        Spi_CreateSlave();
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(SpiSlave, HardwareSetup)
{
    // Set up SPI hardware to our current spec
    mock().expectOneCall("ATtinySpi_SetWireMode")
          .withParameter("wireMode", USI_THREE_WIRE);
    mock().expectOneCall("ATtinySpi_SetClockSource")
          .withParameter("clockSource", USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    mock().expectOneCall("ATtinySpi_ConfigureUsiPins")
          .withParameter("masterOrSlave", SPI_SLAVE)
          .withParameter("pinPosition", SPI_PORTA_PINS);
    mock().expectOneCall("ATtinySpi_EnableCounterOverflowInterrupts")
          .withParameter("enableInterrupts", TRUE);
    mock().expectOneCall("ATtinySpi_SetIsTransmittingFlag")
          .withParameter("isTransmitting", FALSE);

    // Timer0 is not needed

    Spi_HwSetup();
}

TEST(SpiSlave, UsiOverflowInterrupt)
{
    mock().expectOneCall("ATtinySpi_ClearCounterOverflowInterruptFlag");
    mock().expectOneCall("ATtinySpi_SetIsTransmittingFlag")
        .withParameter("isTransmitting", FALSE);
    mock().expectOneCall("ATtinySpi_SaveInputData");

    Spi_UsiOverflowInterrupt();
}

//TODO is this correct? Read the docs and check.
TEST(SpiSlave, SendDataWithDevicePrepared)
{
    u08 data = 42;
    mock().expectOneCall("ATtinySpi_PrepareOutputData")
        .withParameter("data", data);

    Spi_SendData(data);
}
