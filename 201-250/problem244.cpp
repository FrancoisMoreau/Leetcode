//
// Created by brayden on 2020-02-21.
//

#include "problem244.h"

WordDistance::WordDistance(vector<string> &words) {
    for (int i = 0; i < words.size(); ++i) {
        location[words[i]].push_back(i);
    }
}


int WordDistance::shortest(string word1, string word2) {
    auto it0 = location[word1].cbegin();
    auto it1 = location[word2].cbegin();
    int shortes_dis = INT_MAX;
    while (it0 != location[word1].cend()  && it1 != location[word2].cend()) {
        if (*it0 > *it1) {
            shortes_dis = std::min(shortes_dis, *it0 - *it1);
            ++it1;
        } else {
            shortes_dis = std::min(shortes_dis, *it1 - *it0);
            ++it0;
        }
    }
    return shortes_dis;
}