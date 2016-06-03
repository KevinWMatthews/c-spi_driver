#ifndef __ATtinySpi_H
#define __ATtinySpi_H

#include "DataTypes.h"

typedef enum
{
    USI_PARTIAL_DISABLE = 0b00,
    USI_THREE_WIRE      = 0b01,
    USI_TWO_WIRE_1      = 0b10,
    USI_TWO_WIRE_2      = 0b11    //Don't know the difference. Look it up.
} Usi_WireMode;
#define BITMASK_SPI_WIRE_MODE ((1<<USIWM1) | (1<<USIWM0))
void ATtinySpi_SetWireMode(Usi_WireMode wireMode);

typedef enum
{
    USI_NONE                                   = 0b000,
    USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE = 0b101,   //Spi mode 0
    USI_EXTERNAL_NEGATIVE_EDGE_SOFTWARE_STROBE = 0b111    //Spi mode 1
} Usi_ClockSource;
#define BITMASK_SPI_CLOCK_SOURCE ((1<<USICS1) | (1<<USICS0) | (1<<USICLK))
void ATtinySpi_SetClockSource(Usi_ClockSource clockSource);

typedef enum
{
    SPI_PORTB_PINS = 0,
    SPI_PORTA_PINS = 1
} Spi_PinPosition;
typedef enum
{
    SPI_MASTER = 0,
    SPI_SLAVE  = 1
} Spi_DeviceType;
#define USI_MISO_BIT_A 0
#define USI_MOSI_BIT_A 1
#define USI_USCK_BIT_A 2
#define USI_MISO_BIT_B 0
#define USI_MOSI_BIT_B 1
#define USI_USCK_BIT_B 2
void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition);

#define BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS (1<<USIOIE)
void ATtinySpi_SetCounterOverflowInterrupts(BOOL enableInterrupts);

void ATtinySpi_SetIsTransmittingFlag(BOOL isTransmitting);
BOOL ATtinySpi_GetIsTransmittingFlag(void);

#endif
