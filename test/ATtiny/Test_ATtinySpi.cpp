extern "C"
{
#include "ATtinySpi.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "Test_ATtinySpi.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(WhenSettingAllBits)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(WhenSettingAllBits, ItCanFail)
{
    FAIL("Start here");
}
