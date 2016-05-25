extern "C"
{
#include "ATtinyTimer0.h"
}

#include "CppUTestExt/MockSupport.h"

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
