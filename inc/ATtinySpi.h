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
void ATtinySpi_SetWireMode(Usi_WireMode wireMode);

typedef enum
{
    USI_NONE                                   = 0b000,
    USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE = 0b101,   //Spi mode 0
    USI_EXTERNAL_NEGATIVE_EDGE_SOFTWARE_STROBE = 0b111    //Spi mode 1
} Usi_ClockSource;
void ATtinySpi_SetClockSource(Usi_ClockSource clockSource);

typedef enum
{
    SPI_PORTA_PINS = 1,
    SPI_PORTB_PINS = 0
} Spi_PinPosition;
typedef enum
{
    SPI_MASTER = 0,
    SPI_SLAVE  = 1
} Spi_DeviceType;
void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition);

void ATtinySpi_EnableCounterOverflowInterrupts(BOOL enableInterrupts);
void ATtinySpi_ClearCounterOverflowInterruptFlag(void);

void ATtinySpi_SetIsTransmittingFlag(BOOL isTransmitting);
BOOL ATtinySpi_GetIsTransmittingFlag(void);

void ATtinySpi_PrepareOutputData(u08);
void ATtinySpi_SaveInputData(void);

void ATtinySpi_ToggleUsiClock(void);

#endif
