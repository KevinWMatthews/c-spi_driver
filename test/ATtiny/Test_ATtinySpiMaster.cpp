extern "C"
{
#include "ATtinySpiMaster.h"
#include "ATtinySpiPrivate.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinySpiMaster.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtinySpiMaster)
{
    uint8_t expected;

    void setup()
    {
        expected = 0;
    }

    void teardown()
    {
    }
};

TEST(ATtinySpiMaster, ItCanFail)
{
    FAIL("FAIL");
}
