extern "C"
{
#include "ATtinyTimer0.h"
}

#include "CppUTestExt/MockSupport.h"

void ATtinyTimer0_SetTimerBitWidth(Timer0BitWidth timerBitWidth)
{
    mock().actualCall("ATtinyTimer0_SetTimerBitWidth")
          .withParameter("timerBitWidth", timerBitWidth);
}

void ATtinyTimer0_ClearTimerOnMatch(BOOL clearOnMatchFlag)
{
    mock().actualCall("ATtinyTimer0_ClearTimerOnMatch")
          .withParameter("clearOnMatchFlag", clearOnMatchFlag);
}

void ATtinyTimer0_SetPrescaleFactor(Timer0_PrescaleFactor prescaleFactor)
{
    mock().actualCall("ATtinyTimer0_SetPrescaleFactor")
          .withParameter("prescaleFactor", prescaleFactor);
}

void ATtinyTimer0_SetTimerCompareValue0A(u08 timerCompareValue)
{
    mock().actualCall("ATtinyTimer0_SetTimerCompareValue0A")
          .withParameter("timerCompareValue", timerCompareValue);
}

void ATtinyTimer0_SetTimerCompareInterrupt0A(BOOL enableInterrupt)
{
    mock().actualCall("ATtinyTimer0_SetTimerCompareInterrupt0A")
          .withParameter("enableInterrupt", enableInterrupt);
}
