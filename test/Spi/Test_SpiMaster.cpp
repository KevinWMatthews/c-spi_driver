extern "C"
{
#include "SpiMaster.h"
#include "ATtinySpi.h"
#include "ATtinyTimer0.h"
}

#include "Test_SpiMaster.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(SpiMaster)
{
    void setup()
    {
        mock().strictOrder();
        Spi_CreateMaster();
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(SpiMaster, HardwareSetup)
{
    // Set up SPI hardware to our current spec
    mock().expectOneCall("ATtinySpi_SetWireMode")
          .withParameter("wireMode", USI_THREE_WIRE);
    mock().expectOneCall("ATtinySpi_SetClockSource")
          .withParameter("clockSource", USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    mock().expectOneCall("ATtinySpi_ConfigureUsiPins")
          .withParameter("masterOrSlave", SPI_MASTER)
          .withParameter("pinPosition", SPI_PORTA_PINS);
    mock().expectOneCall("ATtinySpi_EnableCounterOverflowInterrupts")
          .withParameter("enableInterrupts", TRUE);

    // Set up Timer0 to our current spec
    mock().expectOneCall("ATtinyTimer0_SetTimerBitWidth")
          .withParameter("timerBitWidth", T0_EIGHT_BIT);
    mock().expectOneCall("ATtinyTimer0_ClearTimerOnMatch")
          .withParameter("clearOnMatchFlag", TRUE);
    mock().expectOneCall("ATtinyTimer0_SetPrescaleFactor")
          .withParameter("prescaleFactor", T0_PRESCALE_FACTOR_64);
    mock().expectOneCall("ATtinyTimer0_SetTimerCompareValue0A")
          .withParameter("timerCompareValue", 125);
    mock().expectOneCall("ATtinyTimer0_EnableTimerCompareInterrupt0A")
          .withParameter("enableInterrupt", FALSE);

    Spi_HwSetup();
}

TEST(SpiMaster, UsiOverflowInterrupt)
{
    mock().expectOneCall("ATtinyTimer0_EnableTimerCompareInterrupt0A")
        .withParameter("enableInterrupt", FALSE);
    mock().expectOneCall("ATtinySpi_ClearCounterOverflowInterruptFlag");
    mock().expectOneCall("ATtinySpi_SaveInputData");

    Spi_UsiOverflowInterrupt();
}

TEST(SpiMaster, SendDataWithDevicePrepared)
{
    u08 data = 42;
    mock().expectOneCall("ATtinySpi_PrepareOutputData")
        .withParameter("data", data);
    mock().expectOneCall("ATtinySpi_SelectSlave");
    mock().expectOneCall("ATtinyTimer0_EnableTimerCompareInterrupt0A")
        .withParameter("enableInterrupt", TRUE);

    Spi_SendData(data);
}

TEST(SpiMaster, ClockOverflowInterrupt)
{
    mock().expectOneCall("ATtinySpi_ToggleUsiClock");
    SpiMaster_ClockInterrupt();
}

TEST(SpiMaster, GetReceivedDataSuccessfully)
{
    u08 received = 0, status = 0;
    mock().expectOneCall("ATtinySpi_GetData")
          .andReturnValue(42);

    status = Spi_GetData(&received);

    LONGS_EQUAL(SPI_DATA_RECEIVED, status);
    LONGS_EQUAL(42, received);
}

/*
 * Test list:
 *   GetData must handle NULL pointer.
 *   GetData must return NO_TRANSMISSION/NO_DATA status.
 *   GetData must return TRANSMISSION_IN_PROGRESS status.
 *   GetData must catch data from old transmission after it's finished.
 *   GetData must catch data from old transmission while a new one is in progress.
 */
