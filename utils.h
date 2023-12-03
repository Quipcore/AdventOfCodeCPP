//
// Created by felix on 2023-08-20.
//

#ifndef ADVENTOFCODECPP_UTILS_H
#define ADVENTOFCODECPP_UTILS_H


#include <vector>
#include <string>

class utils {
public:
    static std::vector<std::string>* createPuzzleVector(const std::string& path);

    static std::vector<std::string> split(std::string s, std::string delimiter);

    static void trim(std::string *str);
};


#endif //ADVENTOFCODECPP_UTILS_H
