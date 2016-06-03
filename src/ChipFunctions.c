#include "ChipFunctions.h"
#include "BitManip.h"

void ChipFunctions_SetPinAsOutput(RegisterPointer dataDirectionRegister, u08 bitNumber)
{
    SET_BIT_NUMBER(*dataDirectionRegister, bitNumber);
}

void ChipFunctions_SetPinAsInput(RegisterPointer dataDirectionRegister, u08 bitNumber)
{
    CLEAR_BIT_NUMBER(*dataDirectionRegister, bitNumber);
}

void ChipFunctions_EnablePullUpResistor(RegisterPointer portRegister, u08 bitNumber)
{
    SET_BIT_NUMBER(*portRegister, bitNumber);
}

void ChipFunctions_DisablePullUpResistor(RegisterPointer portRegister, u08 bitNumber)
{
    CLEAR_BIT_NUMBER(*portRegister, bitNumber);
}
