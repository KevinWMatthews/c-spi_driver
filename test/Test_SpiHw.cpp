extern "C"
{
#include "SpiHw.h"
#include "ATtiny.h"
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

TEST(WhenInitializingHardware, ItCanCompleteSlaveSetup)
{
    mock().expectOneCall("ATtiny_SetWireMode")
          .withParameter("wireMode", USI_THREE_WIRE);
    mock().expectOneCall("ATtiny_SetClockSource")
          .withParameter("clockSource", USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE);
    // mock().expectOneCall("SpiHw_ConfigureUsiPins")
    //       .withParameter("masterOrSlave", SPI_SLAVE)
    //       .withParameter("pinPosition", SPI_PORTA_PINS);
    // mock().expectOneCall("SpiHw_SetCounterOverflowInterrupts")
    //       .withParameter("enableInterrupts", TRUE);
    // mock().expectOneCall("SpiHw_SetIsTransmittingFlag")
    //       .withParameter("isTransmitting", FALSE);

    SpiHw_SetupAsSlave();
}
