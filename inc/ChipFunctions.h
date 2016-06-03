#ifndef __ChipFunctions_H
#define __ChipFunctions_H

#include "DataTypes.h"

void ChipFunctions_SetPinAsOutput(RegisterPointer dataDirectionRegister, u08 bitNumber);
void ChipFunctions_SetPinAsInput(RegisterPointer dataDirectionRegister, u08 bitNumber);
void ChipFunctions_EnablePullUpResistor(RegisterPointer portRegister, u08 bitNumber);
void ChipFunctions_DisablePullUpResistor(RegisterPointer portRegister, u08 bitNumber);

#endif
