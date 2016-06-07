extern "C"
{
#include "ATtinySpiMaster.h"
#include "ATtinySpiPrivate.h"
#include "ATtinySpiBitmasks.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinySpiMaster.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtinySpiMaster)
{
    uint8_t expectedDDR;
    uint8_t expectedUSIPP;
    uint8_t expectedPORT;

    void setup()
    {
        expectedUSIPP = 0x5a;
        expectedDDR   = 0x5a;
        expectedPORT  = 0x5a;
        USIPP = 0x00;
        DDRA  = 0x00;
        PORTA = 0x00;
        DDRB  = 0x00;
        PORTB = 0x00;
    }

    void teardown()
    {
    }
};

TEST(ATtinySpiMaster, SetMasterPinPositionToPortA)
{
    expectedDDR   = 0x00;
    expectedUSIPP = 0x00;
    expectedPORT  = 0x00;

    SET_BIT_NUMBER(expectedUSIPP, USIPOS);
    CLEAR_BIT_NUMBER(expectedDDR, USI_MISO_BIT_A);  //Input:   MISO
    SET_BIT_NUMBER(expectedDDR, USI_MOSI_BIT_A);    //Output:  MOSI
    SET_BIT_NUMBER(expectedDDR, USI_USCK_BIT_A);    //Output:  SCK
    SET_BIT_NUMBER(expectedPORT, USI_MISO_BIT_A);   //Pull-up: MISO

    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTA_PINS);

    BYTES_EQUAL(expectedUSIPP, USIPP);
    BYTES_EQUAL(expectedDDR, DDRA);
    BYTES_EQUAL(expectedPORT, PORTA);
}

TEST(ATtinySpiMaster, SetMasterPinPositionToPortB)
{
    expectedDDR   = 0x00;
    expectedUSIPP = 0x00;
    expectedPORT  = 0x00;

    CLEAR_BIT_NUMBER(expectedUSIPP, USIPOS);
    CLEAR_BIT_NUMBER(expectedDDR, USI_MISO_BIT_B);  //Input:   MISO
    SET_BIT_NUMBER(expectedDDR, USI_MOSI_BIT_B);    //Output:  MOSI
    SET_BIT_NUMBER(expectedDDR, USI_USCK_BIT_B);    //Output:  USCK
    SET_BIT_NUMBER(expectedPORT, USI_MISO_BIT_B);   //Pull-up: MISO

    ATtinySpi_ConfigureUsiPins(SPI_MASTER, SPI_PORTB_PINS);

    BYTES_EQUAL(expectedUSIPP, USIPP);
    BYTES_EQUAL(expectedDDR, DDRB);
    BYTES_EQUAL(expectedPORT, PORTB);
}
