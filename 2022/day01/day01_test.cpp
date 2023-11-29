#include <gtest/gtest.h>
#include "day01.h"

// Demonstrate some basic assertions.
TEST(Day01_2022, BasicAssertions) {

    year2022::day01 day01;
    EXPECT_EQ(day01.part1(), 0);
}