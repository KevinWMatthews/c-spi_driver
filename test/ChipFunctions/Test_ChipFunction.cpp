extern "C"
{
#include "ChipFunctions.h"
}

#include "Test_ChipFunctions.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ChipFunctionsATtiny861)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ChipFunctionsATtiny861, ItCanSetAPinAsOutput)
{
    u08 memory = 0;
    RegisterPointer memoryPointer = &memory;

    ChipFunctions_SetPinAsOutput(memoryPointer, 7);
    BYTES_EQUAL( 1<<7, memory );
}

TEST(ChipFunctionsATtiny861, ItCanSetAPinAsInput)
{
    u08 memory = 0xff;
    RegisterPointer memoryPointer = &memory;

    ChipFunctions_SetPinAsInput(memoryPointer, 7);
    BYTES_EQUAL( ~(1<<7), memory );
}

TEST(ChipFunctionsATtiny861, ItCanEnableAPullUpResistor)
{
    u08 memory = 0;
    RegisterPointer memoryPointer = &memory;

    ChipFunctions_EnablePullUpResistor(memoryPointer, 7);
    BYTES_EQUAL( 1<<7, memory );
}

TEST(ChipFunctionsATtiny861, ItCanDisableAPullUpResistor)
{
    u08 memory = 0xff;
    RegisterPointer memoryPointer = &memory;

    ChipFunctions_DisablePullUpResistor(memoryPointer, 7);
    BYTES_EQUAL( ~(1<<7), memory );
}
