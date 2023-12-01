
#include "gtest/gtest.h"
#include "day01.h"

TEST(Day01_P1_2023, BasicAssertions) {
    year2023::day01 day01("../2023/day01/testdata.txt");
    EXPECT_EQ(day01.part1(), 142);
}

TEST(Day01_P2_2023, BasicAssertions) {
    year2023::day01 day01("../2023/day01/testdata.txt");
    EXPECT_EQ(day01.part2(), 281);
}