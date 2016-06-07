#include "ATtinySpi.h"
#include "ATtinySpiBitmasks.h"
#include "ATtinySpiPrivate.h"
#include <avr/io.h>
#include "BitManip.h"
#include "ChipFunctions.h"

ATtinySpiInterface interface;

void ATtinySpi_SetWireMode(Usi_WireMode wireMode)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, wireMode, BITMASK_SPI_WIRE_MODE);
}

void ATtinySpi_SetClockSource(Usi_ClockSource clockSource)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, clockSource, BITMASK_SPI_CLOCK_SOURCE);
}

void ATtinySpi_EnableCounterOverflowInterrupts(BOOL enableInterrupts)
{
    SHIFT_AND_SET_BITMASK_TO(USICR, enableInterrupts, BITMASK_USI_COUNTER_OVERFLOW_INTERRUPTS);
}

static void setPinPositionForMasterPortA(void)
{
    ATtinySpiMaster_SetPinPositionForMasterPortA();
}

static void setPinPositionForMasterPortB(void)
{
    SHIFT_AND_SET_BITMASK_TO(USIPP, SPI_PORTB_PINS, BITMASK_USI_PIN_POSITION);
    ChipFunctions_SetPinAsInput(&DDRB, USI_MISO_BIT_B);
    ChipFunctions_SetPinAsOutput(&DDRB, USI_MOSI_BIT_B);
    ChipFunctions_SetPinAsOutput(&DDRB, USI_USCK_BIT_B);
    ChipFunctions_EnablePullUpResistor(&PORTB, USI_MISO_BIT_B);
}

static void setPinPositionForSlavePortA(void)
{
    SHIFT_AND_SET_BITMASK_TO(USIPP, SPI_PORTA_PINS, BITMASK_USI_PIN_POSITION);
    ChipFunctions_SetPinAsOutput(&DDRA, USI_MOSI_BIT_A);
    ChipFunctions_SetPinAsInput(&DDRA, USI_USCK_BIT_A);
    ChipFunctions_EnablePullUpResistor(&PORTA, USI_MISO_BIT_A);
    ChipFunctions_EnablePullUpResistor(&PORTA, USI_USCK_BIT_A);
}

static void setPinPositionForSlavePortB(void)
{
    SHIFT_AND_SET_BITMASK_TO(USIPP, SPI_PORTB_PINS, BITMASK_USI_PIN_POSITION);
    ChipFunctions_SetPinAsInput(&DDRB, USI_MISO_BIT_B);
    ChipFunctions_SetPinAsOutput(&DDRB, USI_MOSI_BIT_B);
    ChipFunctions_SetPinAsInput(&DDRB, USI_USCK_BIT_B);
    ChipFunctions_EnablePullUpResistor(&PORTB, USI_MISO_BIT_B);
    ChipFunctions_EnablePullUpResistor(&PORTB, USI_USCK_BIT_B);
}

void ATtinySpi_ConfigureUsiPins(Spi_DeviceType masterOrSlave, Spi_PinPosition pinPosition)
{
    if (masterOrSlave == SPI_MASTER)
    {
        if (pinPosition == SPI_PORTA_PINS)
        {
            setPinPositionForMasterPortA();
        }
        else if (pinPosition == SPI_PORTB_PINS)
        {
            setPinPositionForMasterPortB();
        }
    }
    else if (masterOrSlave == SPI_SLAVE)
    {
        if (pinPosition == SPI_PORTA_PINS)
        {
            setPinPositionForSlavePortA();
        }
        else if (pinPosition == SPI_PORTB_PINS)
        {
            setPinPositionForSlavePortB();
        }
    }
}
