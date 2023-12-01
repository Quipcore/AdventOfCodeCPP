//
// Created by felix on 2023-08-17.
//

#include <algorithm>
#include <utility>
#include "day01.h"
#include "../../utils.h"

const std::string puzzlePath = "../2022/day01/puzzledata.txt";

int year2022::day01::part1() {
    std::vector<std::string> puzzleVector = utils::createPuzzleVector(puzzlePath);

    int currentMax = -1;
    int calorieSum = 0;
    for(const auto & i : puzzleVector)
    {
        if(i.empty()){
            currentMax = std::max(currentMax, calorieSum);
            calorieSum = 0;
            continue;
        }

        calorieSum += std::stol (i);
    }
    return currentMax;
}

int year2022::day01::part2() {
    std::vector<std::string> puzzleVector = utils::createPuzzleVector(puzzlePath);

    std::vector<int> calories;
    int calorieSum = 0;
    for(const auto & str : puzzleVector)
    {
        if(str.empty()){
            calories.push_back(calorieSum);
            calorieSum = 0;
            continue;
        }

        calorieSum += std::stol(str);
    }

    std::sort(calories.begin(), calories.end());
    int calorieEnd = calories.size();
    int sum = 0;
    for(int i = calorieEnd-1; i > calorieEnd-4; --i){
        sum += calories[i];
    }
    return sum;
}
