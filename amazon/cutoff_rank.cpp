//
// Created by brayden on 2020-10-13.
//

#include "cutoff_rank.h"
#include <map>

int cutoff_rank(int cutoff, std::vector<int> scores) {
    std::map<int, int, std::greater<>> dict;
    for (int score : scores)
        dict[score]++;
    int count = 0;
    dict.erase(0);
    for (auto it = dict.begin(); it != dict.end(); it++) {
        count += it->second;
        if (count >= cutoff) {
            break;
        }
    }
    return count;
}

// the other problem: Maxprofit