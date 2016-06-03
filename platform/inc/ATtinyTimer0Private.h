#ifndef __ATtinyTimer0Private_H
#define __ATtinyTimer0Private_H

// These bitmasks are exposed to make testing easier.
#define BITMASK_T0_TIMER_BIT_WIDTH (1<<TCW0)
#define BITMASK_T0_CLEAR_TIMER_ON_MATCH (1<<CTC0)
#define BITMASK_T0_PRESCALE_FACTOR ((1<<CS02) | (1<<CS01) | (1<<CS00))
#define BITMASK_T0_COMPARE_INTERRUPT_0A (1<<OCIE0A)

#endif
