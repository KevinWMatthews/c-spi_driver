extern "C"
{
#include "ATtinyTimer0.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinyTimer0.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtinyTimer0)
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

TEST(ATtinyTimer0, ItClearsMockRegistersAfterSetup)
{
    BYTES_EQUAL(0, expected);
    BYTES_EQUAL(0, TCCR0A);
}

TEST(ATtinyTimer0, ItCanSetAlBitsInTimer0BitWidth)
{
    SET_BITMASK(expected, BITMASK_T0_TIMER_BIT_WIDTH);

    ATtinyTimer0_SetTimerBitWidth(T0_SIXTEEN_BIT);

    BYTES_EQUAL(expected, TCCR0A);
}
