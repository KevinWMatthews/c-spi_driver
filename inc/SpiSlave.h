#ifndef __SpiSlave_H
#define __SpiSlave_H

#include "Spi.h"

// This is a single-instance module. You may either create a master or a slave.
void Spi_CreateSlave(void);
void Spi_StartConditionInterrupt(void);

#endif
