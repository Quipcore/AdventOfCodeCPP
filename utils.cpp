//
// Created by felix on 2023-08-20.
//

#include <fstream>
#include "utils.h"

std::vector<std::string> utils::createPuzzleVector(const std::string& path) {
    std::fstream file;
    file.open(path,std::ios::in);

    std::vector<std::string> puzzleVector;

    if(file.is_open()){
        std::string line;
        while(std::getline(file,line)){
            puzzleVector.push_back(line);
        }
    }

    file.close();
    return puzzleVector;
}
