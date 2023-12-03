//
// Created by felix on 2023-12-02.
//

#ifndef ADVENTOFCODECPP_DAY02_H
#define ADVENTOFCODECPP_DAY02_H

#include <vector>
#include <regex>
#include "../../IDay.h"
namespace year2023{
    class Day03 : public IDay{
    public:
        Day03(std::string path);
        int part2() override;
        int part1() override;
    private:
        std::string puzzlePath;
        std::string bannedChars;
        void search(std::vector<std::pair<int,int>*>*, std::vector<std::pair<int,int>*>*,std::vector<std::string>*);
        bool isAdjecent(int row, int col, std::vector<std::string> *data);

        std::vector<int> foo(std::string &above) const;
    };

}



#endif //ADVENTOFCODECPP_DAY02_H
