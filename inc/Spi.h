#ifndef __Spi_H
#define __Spi_H

#include "DataTypes.h"

void Spi_HwSetup(void);
void Spi_UsiOverflowInterrupt(void);
void Spi_SendData(u08 data);

#endif
