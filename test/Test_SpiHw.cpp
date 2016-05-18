extern "C"
{
#include "SpiHw.h"
#include "ATtinySpi.h"
}

#include "Test_SpiHw.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(WhenInitializingHardware)
{
    void setup()
    {
        mock().strictOrder();
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(WhenInitializingHardware, ItCanCompleteSlaveSetupOnPortA)
{
    mock().expectOneCall("ATtinySpi_SetWireMode")
          .withParameter("wireMode", USI_THREE_WIRE);
    mock().expectOneCall("ATtinySpi_SetClockSource")
          .withParameter("clockSource", USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    mock().expectOneCall("ATtinySpi_ConfigureUsiPins")
          .withParameter("masterOrSlave", SPI_SLAVE)
          .withParameter("pinPosition", SPI_PORTA_PINS);
    mock().expectOneCall("ATtinySpi_SetCounterOverflowInterrupts")
          .withParameter("enableInterrupts", TRUE);
    mock().expectOneCall("ATtinySpi_SetIsTransmittingFlag")
          .withParameter("isTransmitting", FALSE);

    SpiHw_SetupAsSlave();
}

TEST(WhenInitializingHardware, ItCanCompleteMasterSetupOnPortA)
{
  //Set up SpiHw
  mock().expectOneCall("ATtinySpi_SetWireMode")
        .withParameter("wireMode", USI_THREE_WIRE);
  mock().expectOneCall("ATtinySpi_SetClockSource")
        .withParameter("clockSource", USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
  mock().expectOneCall("ATtinySpi_ConfigureUsiPins")
        .withParameter("masterOrSlave", SPI_MASTER)
        .withParameter("pinPosition", SPI_PORTA_PINS);
  mock().expectOneCall("ATtinySpi_SetCounterOverflowInterrupts")
        .withParameter("enableInterrupts", TRUE);
  mock().expectOneCall("ATtinySpi_SetIsTransmittingFlag")
        .withParameter("isTransmitting", FALSE);

  //Set up Timer0
  // mock().expectOneCall("ATtinyTimer0_SetTimerBitWidth")
        // .withParameter("timerBitWidth", T0_EIGHT_BIT);
  // mock().expectOneCall("Timer0_ClearTimerOnMatch")
  //       .withParameter("clearOnMatchFlag", TRUE);
  // mock().expectOneCall("Timer0_SetPrescaleFactor")
  //       .withParameter("prescaleFactor", T0_PRESCALE_FACTOR_64);
  // mock().expectOneCall("Timer0_SetTimerCompareValue0A")
  //       .withParameter("timerCompareValue", 125);
  // mock().expectOneCall("Timer0_SetTimerCompareInterrupt0A")
  //       .withParameter("enableInterrupt", FALSE);

  SpiHw_SetupAsMaster();
}
