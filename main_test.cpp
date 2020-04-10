#include <vector>
#include "gtest/gtest.h"
#include "tests/test.cpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}