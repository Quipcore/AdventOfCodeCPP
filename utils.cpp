//
// Created by felix on 2023-08-20.
//

#include <fstream>
#include "utils.h"

std::vector<std::string>* utils::createPuzzleVector(const std::string& path) {
    std::fstream file;
    file.open(path,std::ios::in);

    auto* puzzleVector = new std::vector<std::string>();

    if(file.is_open()){
        std::string line;

        bool skipNextLine = false;
        while(std::getline(file,line)){
            if(line == "*/"){
                skipNextLine = false;
                continue;
            }
            if(line == "/*"){
                skipNextLine = true;
            }
            if(!skipNextLine) {
                puzzleVector->push_back(line);
            }
        }
    }

    file.close();
    return puzzleVector;
}

void utils::trim(std::string *str){
    int i = 0;
    while(str->at(i) == ' '){
        i++;
    }
    *str = str->substr(i);
}

//From https://stackoverflow.com/a/46931770
std::vector<std::string> utils::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    for(int i = 0; i < res.size(); i++){
        std::string person = res.at(i);
        if(person.empty()){
            res.erase(res.begin()+i);
            --i;
        }
    }

    return res;
}
