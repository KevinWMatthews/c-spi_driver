extern "C"
{
#include "ChipFunctions.h"
}

#include "Test_ChipFunctions.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(Something)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Something, ItCanFail)
{
    FAIL("flunk")
}
