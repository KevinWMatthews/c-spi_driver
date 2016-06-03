#ifndef __io_H
#define __io_H

// These variables hail from chip-specific avr/io*.h files.
// Rather than recreate the entire nested file structure,
// I put them all here until I have a reason for a more complex structure.

// Refer to io.h, iotnx61.h, iotn861a.h

#include <stdint.h>



//*****************//
//*** Port pins ***//
//*****************//
extern uint8_t DDRA;
// #define DDRA _SFR_IO8(0x1A)
#define DDA0 0
#define DDA1 1
#define DDA2 2
#define DDA3 3
#define DDA4 4
#define DDA5 5
#define DDA6 6
#define DDA7 7

extern uint8_t PORTA;
// #define PORTA _SFR_IO8(0x1B)
#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

extern volatile uint8_t DDRB;
// #define DDRB _SFR_IO8(0x17)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

extern volatile uint8_t PORTB;
// #define PORTB _SFR_IO8(0x18)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7



//*********************************************//
//*** Universial Serial Interface registers ***//
//*********************************************//
// USI Control Register
extern uint8_t USICR;
// #define USICR _SFR_IO8(0x0D)
#define USITC  0
#define USICLK 1
#define USICS0 2
#define USICS1 3
#define USIWM0 4
#define USIWM1 5
#define USIOIE 6
#define USISIE 7

// USI Pin Position
extern uint8_t USIPP;
// #define USIPP _SFR_IO8(0x11)
#define USIPOS 0



//***************//
//*** Timer 0 ***//
//***************//
// Timer/Counter0 Control Register A
extern uint8_t TCCR0A;
// #define TCCR0A _SFR_IO8(0x15)
// #define WGM00 0  /* up to at least datasheet rev. B */
#define CTC0  0     /* newer revisions; change not mentioned in revision history */
#define ACIC0 3
#define ICES0 4
#define ICNC0 5
#define ICEN0 6
#define TCW0 7

// Timer/Counter0 Control Register B
extern uint8_t TCCR0B;
// #define TCCR0B  _SFR_IO8(0x33)
#define CS00    0
#define CS01    1
#define CS02    2
#define PSR0    3
#define TSM     4

// Timer/Counter0 Output Compare Register A
extern uint8_t OCR0A;
// #define OCR0A   _SFR_IO8(0x13)

// Timer/Counter0 Interrupt Mask Register
extern uint8_t TIMSK;
// #define TIMSK   _SFR_IO8(0x39)
#define TICIE0  0
#define TOIE0   1
#define TOIE1   2
#define OCIE0B  3
#define OCIE0A  4
#define OCIE1B  5
#define OCIE1A  6
#define OCIE1D  7



#endif
