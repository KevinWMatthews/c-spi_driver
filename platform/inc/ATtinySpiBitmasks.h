#ifndef __ATtinySpiBitmasks_H
#define __ATtinySpiBitmasks_H

// These bitmasks are exposed to make testing easier.
#define BITMASK_SPI_WIRE_MODE ((1<<USIWM1) | (1<<USIWM0))
#define BITMASK_SPI_CLOCK_SOURCE ((1<<USICS1) | (1<<USICS0) | (1<<USICLK))
#define BITMASK_USI_PIN_POSITION (1<<USIPOS)
#define BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS (1<<USIOIE)

#define USI_MISO_BIT_A 0
#define USI_MOSI_BIT_A 1
#define USI_USCK_BIT_A 2
#define USI_MISO_BIT_B 0
#define USI_MOSI_BIT_B 1
#define USI_USCK_BIT_B 2

#endif
