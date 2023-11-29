#include <iostream>
#include "2022/day01/day01.h"
#include "2022/day02/day02.h"
#include <vector>


std::vector<IDay *> getDays(){
    std::vector<IDay*> vector;

    vector.push_back(new year2022::day01);
    vector.push_back(new year2022::day02);

    return vector;
}

int main() {

    for (const auto &item: getDays()){
        item->print();
    }

    return 0;
}