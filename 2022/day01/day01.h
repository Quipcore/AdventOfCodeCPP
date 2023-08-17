//
// Created by felix on 2023-08-17.
//

#ifndef ADVENTOFCODECPP_DAY01_H
#define ADVENTOFCODECPP_DAY01_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "../../IDay.h"

namespace year2022{
    class day01 : public IDay{
    private:
        int part1() override;
        int part2() override;
        std::vector<std::string> createPuzzleVector(std::fstream& file);
    };
}

#endif //ADVENTOFCODECPP_DAY01_H
