#include <iostream>
#include <vector>
#include "2023/day03/Day03.h"
#include "2023/day01/day01.h"
#include "2023/day02/Day02.h"
#include "2022/day01/day01.h"
#include "2022/day02/day02.h"



std::vector<IDay *> getDays(){
    std::vector<IDay*> vector;

//    vector.push_back(new year2022::day01);
//    vector.push_back(new year2022::day02);
//    vector.push_back(new year2023::day01("../2023/day01/puzzledata.txt"));
//    vector.push_back(new year2023::Day02("../2023/day02/puzzledata.txt"));
    vector.push_back(new year2023::Day03("../2023/day03/puzzledata.txt"));

    return vector;
}

int main() {

    for (const auto &item: getDays()){
        item->print();
    }

    return 0;
}