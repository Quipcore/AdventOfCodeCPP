//
// Created by felix on 2023-08-17.
//

#ifndef ADVENTOFCODECPP_DAY01_H
#define ADVENTOFCODECPP_DAY01_H

#include "../../IDay.h"

namespace year2022{
    class day01 : public IDay{
    private:
        int part2() override;

    public:
        int part1() override;
    };
}

#endif //ADVENTOFCODECPP_DAY01_H
