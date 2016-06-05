#ifndef __SpiMaster_H
#define __SpiMaster_H

#include "Spi.h"

// This is a single-instance module. You may either create a master or a slave.
void Spi_CreateMaster(void);
void SpiMaster_ClockInterrupt(void);

#endif
