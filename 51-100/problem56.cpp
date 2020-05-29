//
// Created by brayden on 2020-05-27.
//

#include "problem56.h"

#include <set>
using std::vector;
using std::set;

// Refers to problem352, 50%, 25%
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    set<vector<int>> dict;
    for (auto &i : intervals) {
        auto it = dict.lower_bound(i);
        int start = i[0], end = i[1];
        if (it != dict.begin() && (*(--it))[1] < i[0]) ++it;
        while (it != dict.end() && (*it)[0] <= end && (*it)[1] >= start ) {
            start = std::min(start, (*it)[0]);
            end = std::max(end, (*it)[1]);
            it = dict.erase(it);
        }
        dict.insert(it, {start, end});
    }
    return std::vector<vector<int>>(dict.begin(), dict.end());
}

// another solution with sorting
// 61%, 30%
vector<vector<int>> merge2(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0];});
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < res.back()[1])
            res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }
    return res;
}