//
// Created by brayden on 2020-02-27.
//

#include "problem937.h"
#include <algorithm>

bool log_compare(const string &lhs, const string &rhs) {
    auto lhs_space_idx = lhs.find_first_of(' ');
    auto rhs_space_idx = rhs.find_first_of(' ');
    if (lhs[lhs_space_idx + 1] > 57 && rhs[rhs_space_idx + 1] > 57) {
        if (lhs.substr(lhs_space_idx + 1) == rhs.substr(rhs_space_idx + 1))
            return lhs < rhs;
        else return lhs.substr(lhs_space_idx + 1) < rhs.substr(rhs_space_idx + 1);
    }
    return !isdigit(lhs[lhs_space_idx + 1]);
//    return false;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    std::stable_sort(logs.begin(), logs.end(), log_compare);
    return logs;
}