extern "C"
{
#include "ATtinyTimer0.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinyTimer0.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(WhenSettingRegisterBits)
{
    volatile uint8_t expected;

    void setup()
    {
        expected = 0;
        TCCR0A = 0;
    }

    void teardown()
    {
    }
};

TEST(WhenSettingRegisterBits, ItClearsMockRegistersAfterSetup)
{
    BYTES_EQUAL(0, expected);
    BYTES_EQUAL(0, TCCR0A);
}

TEST(WhenSettingRegisterBits, ItCanSetAllBitsInTimerBitWidth)
{
    SET_BITS(expected, BITMASK_T0_TIMER_BIT_WIDTH);

    ATtinyTimer0_SetTimerBitWidth(T0_SIXTEEN_BIT);

    BYTES_EQUAL(expected, TCCR0A);
}

TEST(WhenSettingRegisterBits, ItCanSetAllBitsInTimerOnMatch)
{
    SET_BITS(expected, BITMASK_T0_CLEAR_TIMER_ON_MATCH);

    ATtinyTimer0_ClearTimerOnMatch(TRUE);

    BYTES_EQUAL(expected, TCCR0A);
}



TEST_GROUP(WhenClearingRegisterBits)
{
    volatile uint8_t expected;

    void setup()
    {
        expected = 0xff;
        TCCR0A = 0xff;
    }

    void teardown()
    {
    }
};

TEST(WhenClearingRegisterBits, ItSetssMockRegistersAfterSetup)
{
    BYTES_EQUAL(0xff, expected);
    BYTES_EQUAL(0xff, TCCR0A);
}

TEST(WhenClearingRegisterBits, ItCanClearAllBitsInTimerBitWidth)
{
    CLEAR_BITS(expected, BITMASK_T0_TIMER_BIT_WIDTH);

    ATtinyTimer0_SetTimerBitWidth(T0_EIGHT_BIT);

    BYTES_EQUAL(expected, TCCR0A);
}

TEST(WhenClearingRegisterBits, ItCanClearAllBitsInTimerOnMatch)
{
    CLEAR_BITS(expected, BITMASK_T0_CLEAR_TIMER_ON_MATCH);

    ATtinyTimer0_ClearTimerOnMatch(FALSE);

    BYTES_EQUAL(expected, TCCR0A);
}
