#include "CppUTest/TestHarness.h"

extern "C"
{
#include "spi_hw.h"
}

TEST_GROUP(WhenCheckingCppUTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(WhenCheckingCppUTest, ItCanFail)
{
    FAIL("EPIC FAIL!")
}
