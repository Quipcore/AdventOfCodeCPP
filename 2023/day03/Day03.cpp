//
// Created by felix on 2023-12-02.
//

#define SPACE_CHAR 0x20

#include "Day03.h"
#include "../../utils.h"
#include <algorithm>
#include "cmath"

year2023::Day03::Day03(std::string path) {
    this->puzzlePath = path;
    this->bannedChars = "0123456789.";
}

int year2023::Day03::part1() {
    std::vector<std::string>* puzzledata = utils::createPuzzleVector(puzzlePath);
    unsigned long long int sum = 0;
    bool skipNum = true;
    for(int row = 0; row < puzzledata->size(); row++){
        std::cout << row << ": ";
        std::string line = puzzledata->at(row);
        int currentValue = 0;
        for (int col = 0; col < line.size(); col++) {
            if(col == line.size() -1 && isdigit(line[col])){
                currentValue *= 10;
                currentValue += line[col] - '0';
                if(!skipNum){
                    if(currentValue != 0){
                        std::cout << currentValue << " ";
                    }
                    sum += currentValue;
                }
                currentValue = 0;
                skipNum = true;
                continue;
            }

            if(!isdigit(line.at(col))){
                if(!skipNum){
                    if(currentValue != 0){
                        std::cout << currentValue << " ";
                    }
                    sum += currentValue;
                }
                currentValue = 0;
                skipNum = true;
                continue;
            }

            if (isAdjecent(row, col, puzzledata)) {
                skipNum = false;
            }

            currentValue *= 10;
            currentValue += line[col] - '0';
        }
        std::cout << std::endl;
    }

    std::cout << sum << std::endl;
    return sum;
}

int year2023::Day03::part2() {
    std::vector<std::string>* puzzledata = utils::createPuzzleVector(puzzlePath);

    auto* gearPositions = new std::vector<std::pair<int,int>*>;
    for(int y = 0; y < puzzledata->size(); y++){
        for(int x = 0; x < puzzledata->at(y).length(); x++){
            if(puzzledata->at(y).at(x) == '*'){
                gearPositions->push_back(new std::pair{x,y});
            }
        }
    }

    auto* gearPairs = new std::vector<std::pair<int,int>*>;
    search(gearPositions, gearPairs,puzzledata);


    unsigned long long int sum = 0;
    for(const auto& item : *gearPairs){
        sum += item->first * item->second;
    }


    return sum;
}

bool year2023::Day03::isAdjecent(int row, int col, std::vector<std::string> *data) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int currentRow = row + i;
            if (currentRow >= data->size() || currentRow < 0) {
                continue;
            }
            int currentCol = col + j;
            std::string str = data->at(currentRow);
            if (currentCol >= str.length() || currentCol < 0) {
                continue;
            }

            if(!bannedChars.contains(str.at(currentCol))){
                return true;
            }
        }
    }
    return false;
}

//Position saved as x,y cords so first is column and second is line
void year2023::Day03::search(std::vector<std::pair<int, int> *> * positions, std::vector<std::pair<int, int> *> * pairs, std::vector<std::string>* data) {
    for(const auto &pos : *positions){
        std::string above = data->at(pos->second-1).substr(pos->first-3,7);
        std::vector<int> nums = foo(above);


        std::string center = data->at(pos->second).substr(pos->first-3,7);
        std::vector<std::string> centerSplits =utils::split(center, "*");
        int centerLeft = 0;
        int centerRight = 0;
        if(isdigit(center.at(2))){
            std::vector<std::string> centerLeftSplit = utils::split(center, ".");
            centerLeft = atoi(centerLeftSplit.at(centerLeftSplit.size()-1).c_str());
        }
        if(isdigit(center.at(4))){
            std::vector<std::string> centerRightSplit = utils::split(center, ".");
            centerLeft = atoi(centerRightSplit.at(0).c_str());
        }
        nums.push_back(centerLeft);
        nums.push_back(centerRight);


        std::string below = data->at(pos->second+1).substr(pos->first-3,7);
        for(int num : foo(below)){
            nums.push_back(num);
        }


        std::vector<int> filterd;
        for(int num : nums){
            if(num != 0){
                filterd.push_back(num);
            }
        }


        if(filterd.size() == 2){
            pairs->push_back(new std::pair<int,int>(filterd.at(0),filterd.at(1)));
        }else{
            pairs->push_back(new std::pair<int,int>(0,0));
        }

    }
    return;
}

std::vector<int> year2023::Day03::foo(std::string &above) const {
    std::vector<std::string> aboveSplits = utils::split(above, ".");

    int aboveRight = 0, aboveLeft = 0;
    if(aboveSplits.size() == 1){
        //if splitsize is one and atleast one digit is adjecent to *
        if(isdigit(above.at(2)) || isdigit(above.at(3)) || isdigit(above.at(4))){
            aboveLeft = atoi(aboveSplits.at(0).c_str());
        }

    }else{

        if(isdigit(above.at(3))){
            if(isdigit(above.at(2))){
                aboveLeft = atoi(aboveSplits.at(0).c_str());
            }
            else if(isdigit(above.at(4))) {
                aboveRight = atoi(aboveSplits.at(1).c_str());
            }
        }

//        Check if middleposition is empty
        else if(!isdigit(above.at(3))){
            if(isdigit(above.at(2))){
                aboveLeft = atoi(aboveSplits.at(0).c_str());
            }

            if(isdigit(above.at(4))) {
                aboveRight = atoi(aboveSplits.at(1).c_str());
            }

//        Check if left of center is empty
        }
        else if(!isdigit(above.at(2))){
            if(isdigit(4)){
                aboveRight = atoi(aboveSplits.at(1).c_str());
            }

        //Check if right of center is empty
        }else if(!isdigit(above.at(4))) {
            if (isdigit(2)) {
                aboveLeft = atoi(aboveSplits.at(0).c_str());
            }
        }
    }

    return {aboveLeft,aboveRight};
}






