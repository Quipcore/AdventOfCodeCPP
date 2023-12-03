//
// Created by felix on 2023-12-01.
//
#include <iostream>
#include <stack>
#include <map>
#include "day01.h"
#include "../../utils.h"



int year2023::day01::part1() {

    std::vector<std::string>* puzzleVector = utils::createPuzzleVector(puzzlePath);
    std::vector<int> numbers;
    for(auto &str : *puzzleVector){
        bool firstNumberFound = false;
        int firstNumber = -1;
        int secondNumber = -1;
        for(char c : str){
            if(c <= '9' && c >= '0'){
                if(!firstNumberFound) {
                    firstNumber = c - '0';
                    firstNumberFound = true;
                }else{
                    secondNumber = c - '0';
                }
            }
        }
        if(secondNumber < 0){
            secondNumber = firstNumber;
        }

        int value = firstNumber * 10 + secondNumber;
        numbers.push_back(value);
    }

    int sum = 0;
    for (const auto &item: numbers){
        sum += item;
    }

    return sum;
}

int year2023::day01::part2() {
    std::vector<std::string>* puzzleVector = utils::createPuzzleVector(puzzlePath);

    std::vector<int> numbers;

    std::map<std::string, int> map = {{"one", 1},
                                      {"two",2},
                                      {"three",3},
                                      {"four",4},
                                      {"five",5},
                                      {"six",6},
                                      {"seven", 7},
                                      {"eight",8},
                                      {"nine",9}};

    for(const auto &item : *puzzleVector){
        bool firstNumberFound = false;
        int first = -1,second = -1;
        for(int i = 0; i < item.size(); i++){

            if(item[i] <= '9' && item[i] >= '0'){
                if(!firstNumberFound){
                    first = item[i] - '0';
                    firstNumberFound = true;
                }else{
                    second = item[i] - '0';
                }
                continue;
            }

            int textBasedNumber = -1;
            std::string substring = item.substr(i,item.size()-i);
            for(const auto &[key, value] : map){
                if(substring.starts_with(key)){
                    textBasedNumber = value;
                }
            }


            if(textBasedNumber == -1){
                continue;
            }

            if(!firstNumberFound){
                first = textBasedNumber;
                firstNumberFound = true;
            }else{
                second = textBasedNumber;
            }
        }

        if(second < 0){
            second = first;
        }

        numbers.push_back(first * 10 + second);

    }

    int sum = 0;
    for (const auto &item: numbers){
        sum += item;
    }

    return sum;
}