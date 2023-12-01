//
// Created by felix on 2023-12-01.
//

#ifndef ADVENTOFCODECPP_DAY01_H
#define ADVENTOFCODECPP_DAY01_H

#include "../../IDay.h"
namespace year2023{
    class day01 : public IDay{
    private:
        std::string puzzlePath;

    public:
        day01(std::string path) : puzzlePath(std::move(path)) {}
        int part1() override;

        int part2() override;
    };
}



#endif //ADVENTOFCODECPP_DAY01_H
