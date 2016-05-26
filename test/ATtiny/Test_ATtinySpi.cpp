extern "C"
{
#include "ATtinySpi.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinySpi.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(WhenSettingAllBits)
{
    uint8_t expected;

    void setup()
    {
        expected = 0;
        USICR = 0;
    }

    void teardown()
    {
    }
};

TEST(WhenSettingAllBits, ItClearsMockRegistersAfterSetup)
{
    LONGS_EQUAL(0, USICR);
}

TEST(WhenSettingAllBits, ItCanSetAllBitsInWireMode)
{
    SET_BITS(expected, BITMASK_SPI_WIRE_MODE);

    ATtinySpi_SetWireMode(USI_TWO_WIRE_2);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenSettingAllBits, ItCanSetAllBitsInClockSource)
{
    SET_BITS(expected, BITMASK_SPI_CLOCK_SOURCE);

    ATtinySpi_SetClockSource(USI_EXTERNAL_NEGATIVE_EDGE_SOFTWARE_STROBE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenSettingAllBits, ItCanSetAllBitsInCounterOverflowInterrupts)
{
    SET_BITS(expected, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);

    ATtinySpi_SetCounterOverflowInterrupts(TRUE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenSettingAllBits, ItCanClearAllBitsInIsTransmittingFlag)
{
    ATtinySpi_SetIsTransmittingFlag(TRUE);
    CHECK( ATtinySpi_GetIsTransmittingFlag() );
}



TEST_GROUP(WhenClearingAllBits)
{
    uint8_t expected;

    void setup()
    {
        expected = 0xff;
        USICR = 0xff;
    }

    void teardown()
    {
    }
};

TEST(WhenClearingAllBits, ItSetsMockRegistersAfterSetup)
{
    LONGS_EQUAL(0xff, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInWireMode)
{
    CLEAR_BITS(expected, BITMASK_SPI_WIRE_MODE);

    ATtinySpi_SetWireMode(USI_PARTIAL_DISABLE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInClockSource)
{
    CLEAR_BITS(expected, BITMASK_SPI_CLOCK_SOURCE);

    ATtinySpi_SetClockSource(USI_NONE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInCounterOverflowInterrupts)
{
    CLEAR_BITS(expected, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);

    ATtinySpi_SetCounterOverflowInterrupts(FALSE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInIsTransmittingFlag)
{
    ATtinySpi_SetIsTransmittingFlag(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);
    CHECK( !ATtinySpi_GetIsTransmittingFlag() );
}
