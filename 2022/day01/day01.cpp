//
// Created by felix on 2023-08-17.
//

#include "day01.h"

const std::string puzzle_path = "../2022/day01/puzzledata.txt";

std::vector<std::string> year2022::day01::createPuzzleVector(std::fstream &file){
    std::vector<std::string> puzzleVector;

    if(file.is_open())
    {
        std::string line;
        while(std::getline(file, line))
        {
            puzzleVector.push_back(line);
        }
    }

    return puzzleVector;
}

int year2022::day01::part1() {
    std::fstream file;
    file.open(puzzle_path, std::ios::in);
    std::vector<std::string> puzzleVector = createPuzzleVector(file);
    file.close();

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
    std::fstream file;
    file.open(puzzle_path, std::ios::in);
    std::vector<std::string> puzzleVector = createPuzzleVector(file);
    file.close();

    std::vector<int> calories;
    int calorieSum = 0;
    for(const auto & i : puzzleVector)
    {
        if(i.empty()){
            calories.push_back(calorieSum);
            calorieSum = 0;
            continue;
        }

        calorieSum += std::stol (i);

    }

    std::sort(calories.begin(), calories.end());
    long calorieEnd = calories.size();
    int sum = 0;
    for(int i = calorieEnd-1; i > calorieEnd-4; --i){
        sum += calories[i];
    }
    return sum;
}
