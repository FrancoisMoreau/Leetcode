//
// Created by brayden on 2020-05-23.
//

#include "problem352.h"

using std::vector;

// My solution, NlogN
vector<vector<int>> SummaryRanges2::getIntervals() {
    if (inset.empty()) return {{}};
    vector<vector<int>> res;
    int prev = *inset.begin(), cur = prev;
    for (auto &i : inset) {
        if (i - cur > 1) {
            res.push_back({prev, cur});
            prev = i;
        }
        cur = i;
    }
    res.push_back({prev, cur});
    return res;
}

void SummaryRanges::addNum(int val) {
    int start = val, end = val;
    auto it = inset.lower_bound({start, end});
    if (it != inset.begin() && (--it)->second + 1 < val) ++it;
    while (it != inset.end() && it->first - 1 <= val && it->second + 1>= val) {
        start = std::min(start, it->first);
        end = std::max(end, it->second);
        it = inset.erase(it);
    }
    inset.insert(it, {start, end});
}

void print(SummaryRanges &obj) {
    vector<vector<int>> res = obj.getIntervals();
    for (auto &i : res) {
        printf("[%d, %d], ", i[0], i[1]);
    }
    printf("\n");
}



