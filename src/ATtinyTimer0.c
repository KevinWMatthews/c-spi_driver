#include "ATtinyTimer0.h"
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
