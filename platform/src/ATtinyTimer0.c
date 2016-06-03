#include "ATtinyTimer0.h"
#include "ATtinyTimer0Private.h"
#include "BitManip.h"
#include <avr/io.h>

void ATtinyTimer0_SetTimerBitWidth(Timer0BitWidth timerBitWidth)
{
    SHIFT_AND_SET_BITMASK_TO(TCCR0A, timerBitWidth, BITMASK_T0_TIMER_BIT_WIDTH);
}

void ATtinyTimer0_ClearTimerOnMatch(BOOL clearOnMatchFlag)
{
    SHIFT_AND_SET_BITMASK_TO(TCCR0A, clearOnMatchFlag, BITMASK_T0_CLEAR_TIMER_ON_MATCH);
}

void ATtinyTimer0_SetPrescaleFactor(Timer0_PrescaleFactor prescaleFactor)
{
    SHIFT_AND_SET_BITMASK_TO(TCCR0B, prescaleFactor, BITMASK_T0_PRESCALE_FACTOR);
}

void ATtinyTimer0_SetTimerCompareValue0A(u08 timerCompareValue)
{
    OCR0A = timerCompareValue;
}

void ATtinyTimer0_EnableTimerCompareInterrupt0A(BOOL enableInterrupt)
{
    SHIFT_AND_SET_BITMASK_TO(TIMSK, enableInterrupt, BITMASK_T0_COMPARE_INTERRUPT_0A);
}
