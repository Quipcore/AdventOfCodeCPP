#include <gtest/gtest.h>
#include "Day02.h"

TEST(Day02_P1_2023, BasicAssertions) {
    year2023::Day02 day02("../2023/day02/testdata.txt");
    EXPECT_EQ(day02.part1(), 8);
}

TEST(Day02_P2_2023, BasicAssertions) {
    year2023::Day02 day02("../2023/day02/testdata.txt");
    EXPECT_EQ(day02.part2(), 2286);
}