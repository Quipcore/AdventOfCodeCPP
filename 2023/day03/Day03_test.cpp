#include <gtest/gtest.h>
#include "Day03.h"

TEST(Day03_P1_2023, BasicAssertions) {
    year2023::Day03 day("../2023/day03/testdata.txt");
    EXPECT_EQ(day.part1(), 4361);
}

TEST(Day03_P2_2023, BasicAssertions) {
    year2023::Day03 day("../2023/day03/testdata.txt");
    EXPECT_EQ(day.part2(), 467835);
}