#ifndef __ATtinyTimer0_H
#define __ATtinyTimer0_H

#include "DataTypes.h"

typedef enum
{
  T0_EIGHT_BIT   = 0,
  T0_SIXTEEN_BIT = 1
} Timer0BitWidth;
#define BITMASK_T0_TIMER_BIT_WIDTH (1<<TCW0)
void ATtinyTimer0_SetTimerBitWidth(Timer0BitWidth timerBitWidth);

#define BITMASK_T0_CLEAR_TIMER_ON_MATCH (1<<CTC0)
void ATtinyTimer0_ClearTimerOnMatch(BOOL clearOnMatchFlag);

typedef enum
{
  T0_TIMER_STOPPED        = 0b000,
  T0_NO_PRESCALING        = 0b001,
  T0_PRESCALE_FACTOR_8    = 0b010,
  T0_PRESCALE_FACTOR_64   = 0b011,
  T0_PRESCALE_FACTOR_1024 = 0b101,
  T0_EXTERNAL_T0_RISING   = 0b111
} Timer0_PrescaleFactor;
#define BITMASK_T0_PRESCALE_FACTOR ((1<<CS02) | (1<<CS01) | (1<<CS00))
void ATtinyTimer0_SetPrescaleFactor(Timer0_PrescaleFactor prescaleFactor);

void ATtinyTimer0_SetTimerCompareValue0A(u08 timerCompareValue);

void ATtinyTimer0_SetTimerCompareInterrupt0A(BOOL enableInterrupt);

#endif
