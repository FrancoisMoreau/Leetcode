//
// Created by brayden on 2020-03-04.
//

#include "problem539.h"

#include <set>
using std::set;

int preprocess(const string &s) {
    auto idx = s.find(':');
    return std::stoi(s.substr(0, idx)) * 60 + std::stoi(s.substr(idx + 1));
}

// checked others' answer, we can sort the string directly too
// Also, it seems that we don't need to use find, directly .substr(0, 2) is totally ok

int findMinDifference(vector<string>& timePoints) {
    int cur_min = 1440;
    vector<int> converted;
    converted.reserve(timePoints.size());
    for (auto &i : timePoints)
        converted.push_back(preprocess(i));
    std::sort(converted.begin(), converted.end());
    for (int i = 1; i < converted.size(); ++i) {
        cur_min = std::min(cur_min, converted[i] - converted[i - 1]);
//        printf("cur: %d\n", cur_min);
    }
    return std::min(cur_min, 1440 + converted.front() - converted.back());
}

//Bucket sort!!! Why I always forget bucket !
int findMinDifference2(vector<string> &timePoints) {
    vector<bool> mark(1440, false);
    for (auto &i : timePoints) {
        int idx = std::stoi(i.substr(0, 2)) * 60 + std::stoi(i.substr(3, 2));
        if (mark[idx]) return 0;
        else mark[idx] = true;
    }
    int prev = 0, min = 1440;
    int first = INT_MAX, last = INT_MIN;
    for (int i = 0; i < 1440; ++i) {
        if (mark[i]) {
            if (first != INT_MAX) {
                min = std::min(min, i - prev);
            }
            first = std::min(first, i);
            last = std::max(i, last);
            prev = i;
        }
    }
    return std::min(min, 1440 - last + first);
}