//
// Created by felix on 2023-12-02.
//

#define SPACE_CHAR 0x20

#include "Day02.h"
#include "../../utils.h"
#include <algorithm>
#include "cmath"

year2023::Day02::Day02(std::string path) {
    this->puzzlePath = path;
}

int year2023::Day02::part1() {

    const int REDS = 12, GREENS = 13, BLUES = 14;
    int sum = 0;
    std::vector<std::string> puzzleVector = utils::createPuzzleVector(puzzlePath);
    for(int id = 0; id < puzzleVector.size(); id++){
        int red = 0, green = 0, blue = 0;

        std::string line = puzzleVector[id].substr(puzzleVector[id].find(':')+2);
        std::vector<std::string> sets = split(line, std::string(";"));

        for(std::string pair : sets){
            trim(&pair);
            std::vector<std::string> tuples = split(pair, ",");
            std::for_each(tuples.begin(), tuples.end(), [this, &blue, &red, &green](std::string &str){
                trim(&str);
                int value = stoi(str);
                std::string color = str.substr(str.find(SPACE_CHAR)+1);

                if(color == "blue"){
                    blue = fmax(blue, value);
                }else if(color == "red"){
                    red = fmax(red, value);
                }else if(color == "green"){
                    green = fmax(green, value);
                }
//                std::cout << value << ", " << color << std::endl;

            });
        }

        if(!(red > REDS || green > GREENS || blue > BLUES)){
            std::cout << id + 1 << std::endl;
            sum += id + 1;
        }
    }
    return sum;
}

int year2023::Day02::part2() {
    const int REDS = 12, GREENS = 13, BLUES = 14;
    int sum = 0;
    std::vector<std::string> puzzleVector = utils::createPuzzleVector(puzzlePath);
    for(int id = 0; id < puzzleVector.size(); id++){
        int red = 0, green = 0, blue = 0;

        std::string line = puzzleVector[id].substr(puzzleVector[id].find(':')+2);
        std::vector<std::string> sets = split(line, std::string(";"));

        for(std::string pair : sets){
            trim(&pair);
            std::vector<std::string> tuples = split(pair, ",");
            std::for_each(tuples.begin(), tuples.end(), [this, &blue, &red, &green](std::string &str){
                trim(&str);
                int value = stoi(str);
                std::string color = str.substr(str.find(SPACE_CHAR)+1);

                if(color == "blue"){
                    blue = fmax(blue, value);
                }else if(color == "red"){
                    red = fmax(red, value);
                }else if(color == "green"){
                    green = fmax(green, value);
                }

            });
        }

        sum += (red * green * blue);
    }
    return sum;
}

void year2023::Day02::trim(std::string *str){
    int i = 0;
    while(str->at(i) == ' '){
        i++;
    }
    *str = str->substr(i);
}

//From https://stackoverflow.com/a/46931770
std::vector<std::string> year2023::Day02::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}




