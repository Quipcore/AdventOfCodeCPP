//
// Created by felix on 2023-08-17.
//

#include <map>
#include "day02.h"
#include "../../utils.h"

const std::string puzzlePath = "../2022/day02/puzzledata.txt";

std::map<char, int> playToPoint = {{'X',1},{'Y',2},{'Z',3}};

int year2022::day02::part1() {
    int sum = 0;
    std::vector<std::string> puzzleVector = utils::createPuzzleVector(puzzlePath);

    for(auto &item : puzzleVector){

    }

    return 0;
}

std::string* split(std::string& str){

    std::string valueToken = str.substr(0, 2);
    std::string keyToken = str.substr(1,2);

    auto* s = new std::string[2];
    s[0] = keyToken;
    s[1] = valueToken;
    return s;
}


int year2022::day02::part2() {
    return 0;
}
