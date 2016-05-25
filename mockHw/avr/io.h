#ifndef __io_H
#define __io_H

// These variables hail from chip-specific avr/io*.h files.
// Rather than recreate the entire nested file structure,
// I put them all here until I have a reason for a more complex structure.

// Refer to io.h, iotnx61.h, iotn861a.h

#include <stdint.h>



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

#endif
