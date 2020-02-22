//
// Created by brayden on 2020-02-21.
//

#ifndef INC_201_250_PROBLEM244_H
#define INC_201_250_PROBLEM244_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::string;
using std::unordered_map;

class WordDistance {
public:
    WordDistance(vector<string>& words);

    int shortest(string word1, string word2);

private:
    unordered_map<string, vector<int>> location;

};


#endif //INC_201_250_PROBLEM244_H
