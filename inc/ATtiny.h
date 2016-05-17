#ifndef __ATtiny_H
#define __ATtiny_H

typedef enum
{
    USI_PARTIAL_DISABLE = 0b00,
    USI_THREE_WIRE      = 0b01,
    USI_TWO_WIRE_1      = 0b10,
    USI_TWO_WIRE_2      = 0b11    //Don't know the difference. Look it up.
} Usi_WireMode;
void ATtiny_SetWireMode(Usi_WireMode wireMode);

typedef enum
{
    USI_NONE                                   = 0b000,
    USI_EXTERNAL_POSITIVE_EDGE_SOFTWARE_STROBE = 0b101,   //Spi mode 0
    USI_EXTERNAL_NEGATIVE_EDGE_SOFTWARE_STROBE = 0b111    //Spi mode 1
} Usi_ClockSource;
void ATtiny_SetClockSource(Usi_ClockSource clockSource);

#endif
