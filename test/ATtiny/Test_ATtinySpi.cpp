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
    SET_BITMASK(expected, BITMASK_SPI_WIRE_MODE);

    ATtinySpi_SetWireMode(USI_TWO_WIRE_2);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenSettingAllBits, ItCanSetAllBitsInClockSource)
{
    SET_BITMASK(expected, BITMASK_SPI_CLOCK_SOURCE);

    ATtinySpi_SetClockSource(USI_EXTERNAL_NEGATIVE_EDGE_SOFTWARE_STROBE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenSettingAllBits, ItCanSetAllBitsInCounterOverflowInterrupts)
{
    SET_BITMASK(expected, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);

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
    CLEAR_BITMASK(expected, BITMASK_SPI_WIRE_MODE);

    ATtinySpi_SetWireMode(USI_PARTIAL_DISABLE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInClockSource)
{
    CLEAR_BITMASK(expected, BITMASK_SPI_CLOCK_SOURCE);

    ATtinySpi_SetClockSource(USI_NONE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInCounterOverflowInterrupts)
{
    CLEAR_BITMASK(expected, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);

    ATtinySpi_SetCounterOverflowInterrupts(FALSE);
    BYTES_EQUAL(expected, USICR);
}

TEST(WhenClearingAllBits, ItCanClearAllBitsInIsTransmittingFlag)
{
    ATtinySpi_SetIsTransmittingFlag(TRUE);
    ATtinySpi_SetIsTransmittingFlag(FALSE);
    CHECK( !ATtinySpi_GetIsTransmittingFlag() );
}



TEST_GROUP(WhenSettingPinPositions)
{
    uint8_t expectedDDR;
    uint8_t expectedUSIPP;
    uint8_t expectedPORT;

    void setup()
    {
        expectedDDR   = 0x5a;
        expectedUSIPP = 0x5a;
        expectedPORT  = 0x5a;
        USIPP = 0x00;
        DDRA  = 0x00;
        PORTA = 0x00;
    }

    void teardown()
    {
    }
};

IGNORE_TEST(WhenSettingPinPositions, ItCanSetToMasterPortA)
{
    expectedDDR   = 0x00;
    expectedUSIPP = 0x00;
    expectedPORT  = 0x00;

    SET_BIT_NUMBER(expectedUSIPP, USIPOS);
    CLEAR_BIT_NUMBER(expectedDDR, USI_MISO_BIT_A);  //Input:   MISO
    SET_BIT_NUMBER(expectedDDR, USI_MOSI_BIT_A);    //Output:  MOSI
    SET_BIT_NUMBER(expectedDDR, USI_USCK_BIT_A);    //Output:  SCK
    SET_BIT_NUMBER(expectedPORT, USI_MISO_BIT_A);   //Pull-up: MISO

    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTA_PINS);
    BYTES_EQUAL(expectedUSIPP, USIPP);
    BYTES_EQUAL(expectedDDR, DDRA);
    BYTES_EQUAL(expectedPORT, PORTA);
}