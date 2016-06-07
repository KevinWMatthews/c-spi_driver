#include "ATtinySpiMaster.h"
#include "ATtinySpiPrivate.h"
#include "ATtinySpiBitmasks.h"
#include <avr/io.h>
#include "BitManip.h"
#include "ChipFunctions.h"

void ATtinySpiMaster_SetPinPositionForMasterPortA(void)
{
    SHIFT_AND_SET_BITMASK_TO(USIPP, SPI_PORTA_PINS, BITMASK_USI_PIN_POSITION);
    ChipFunctions_SetPinAsInput(&DDRA, USI_MISO_BIT_A);
    ChipFunctions_SetPinAsOutput(&DDRA, USI_MOSI_BIT_A);
    ChipFunctions_SetPinAsOutput(&DDRA, USI_USCK_BIT_A);
    ChipFunctions_EnablePullUpResistor(&PORTA, USI_MISO_BIT_A);
}
