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

    // Timer0 is not needed

    Spi_HwSetup();
}

TEST(SpiSlave, UsiOverflowInterrupt)
{
    mock().expectOneCall("ATtinySpi_ClearCounterOverflowInterruptFlag");
    mock().expectOneCall("ATtinySpi_SaveInputData");

    Spi_UsiOverflowInterrupt();
}

TEST(SpiSlave, StartConditionInterrupt)
{
    mock().expectOneCall("ATtinySpi_ClearDataRegister");

    Spi_StartConditionInterrupt();
}

//TODO is this correct? Read the docs and check if slave behavior differs from master behavior.
TEST(SpiSlave, SendDataWithDevicePrepared)
{
    u08 data = 42;
    mock().expectOneCall("ATtinySpi_PrepareOutputData")
        .withParameter("data", data);

    Spi_SendData(data);
}

TEST(SpiSlave, GetReceivedDataSuccessfully)
{
    u08 received = 0, status = 0;
    mock().expectOneCall("ATtinySpi_GetData")
          .andReturnValue(42);

    status = Spi_GetData(&received);

    LONGS_EQUAL(SPI_DATA_RECEIVED, status);
    LONGS_EQUAL(42, received);
}

/* Test list:
 *   Set up an interrupt on a GPIO line to use as a slave select pin.
 *
 *   GetData must handle NULL pointer.
 *   GetData must return NO_TRANSMISSION/NO_DATA status.
 *   GetData must return TRANSMISSION_IN_PROGRESS status.
 *   GetData must catch data from old transmission after it's finished.
 *   GetData must catch data from old transmission while a new one is in progress.
 */
