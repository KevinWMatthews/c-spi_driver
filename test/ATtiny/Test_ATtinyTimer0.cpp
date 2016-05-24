extern "C"
{
#include "ATtinyTimer0.h"
}

#include "Test_ATtinyTimer0.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtinyTimer0)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ATtinyTimer0, ItCanFail)
{
    FAIL("flunk");
}
