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
        TCCR0B = 0;
        OCR0A = 0;
        TIMSK = 0;
    }

    void teardown()
    {
    }
};

TEST(WhenSettingRegisterBits, ItClearsMockRegistersAfterSetup)
{
    BYTES_EQUAL(0, expected);
    BYTES_EQUAL(0, TCCR0A);
    BYTES_EQUAL(0, TCCR0B);
    BYTES_EQUAL(0, OCR0A);
    BYTES_EQUAL(0, TIMSK);
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

TEST(WhenSettingRegisterBits, ItCanSetAllBitsInPrescaler)
{
    SET_BITS(expected, BITMASK_T0_PRESCALE_FACTOR);

    ATtinyTimer0_SetPrescaleFactor(T0_EXTERNAL_T0_RISING);

    BYTES_EQUAL(expected, TCCR0B);
}

TEST(WhenSettingRegisterBits, ItCanSetMaxTimerCompareValue)
{
    ATtinyTimer0_SetTimerCompareValue0A(255);
    LONGS_EQUAL(OCR0A, 255);
}

TEST(WhenSettingRegisterBits, ItCanSetAllBitsInEnableTimerCompareInterrupt)
{
  SET_BITS(expected, BITMASK_T0_COMPARE_INTERRUPT_0A);

  ATtinyTimer0_SetTimerCompareInterrupt0A(TRUE);

  BYTES_EQUAL(expected, TIMSK);
}



TEST_GROUP(WhenClearingRegisterBits)
{
    volatile uint8_t expected;

    void setup()
    {
        expected = 0xff;
        TCCR0A = 0xff;
        TCCR0B = 0xff;
        OCR0A = 0xff;
        TIMSK = 0xff;
    }

    void teardown()
    {
    }
};

TEST(WhenClearingRegisterBits, ItSetssMockRegistersAfterSetup)
{
    BYTES_EQUAL(0xff, expected);
    BYTES_EQUAL(0xff, TCCR0A);
    BYTES_EQUAL(0xff, TCCR0B);
    BYTES_EQUAL(0xff, OCR0A);
    BYTES_EQUAL(0xff, TIMSK);
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

TEST(WhenClearingRegisterBits, ItCanClearAllBitsInPrescaler)
{
    CLEAR_BITS(expected, BITMASK_T0_PRESCALE_FACTOR);

    ATtinyTimer0_SetPrescaleFactor(T0_TIMER_STOPPED);

    BYTES_EQUAL(expected, TCCR0B);
}

TEST(WhenClearingRegisterBits, ItCanSetMinTimerCompareValue)
{
    ATtinyTimer0_SetTimerCompareValue0A(0);
    LONGS_EQUAL(OCR0A, 0);
}


TEST(WhenClearingRegisterBits, ItCanClearAllBitsInEnableTimerCompareInterrupt)
{
  CLEAR_BITS(expected, BITMASK_T0_COMPARE_INTERRUPT_0A);

  ATtinyTimer0_SetTimerCompareInterrupt0A(FALSE);

  BYTES_EQUAL(expected, TIMSK);
}
