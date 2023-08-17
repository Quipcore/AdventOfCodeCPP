//
// Created by felix on 2023-08-17.
//
#ifndef ADVENTOFCODECPP_IDAY_H
#define ADVENTOFCODECPP_IDAY_H

#include "iostream"

class IDay {
public:
    void print(){
        std::cout << "Part 1: " << part1() << ", Part 2: " << part2() << std::endl;
    };
private:
    virtual int part1() = 0;
    virtual int part2() = 0;
};
#endif //ADVENTOFCODECPP_IDAY_H
