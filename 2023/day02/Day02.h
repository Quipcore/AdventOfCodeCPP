//
// Created by felix on 2023-12-02.
//

#ifndef ADVENTOFCODECPP_DAY02_H
#define ADVENTOFCODECPP_DAY02_H

#include <vector>
#include "../../IDay.h"
namespace year2023{

    class Day02 : public IDay{
    public:
        Day02(std::string path);
        int part2() override;
        int part1() override;
    private:
        std::string puzzlePath;

        std::vector<std::string> split(std::string s, std::string delimiter);

        void trim(std::string* str);
    };

}



#endif //ADVENTOFCODECPP_DAY02_H
