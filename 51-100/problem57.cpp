//
// Created by brayden on 2020-06-09.
//

#include "problem57.h"


using std::vector;

// passed 153 cases, TLE at the very end largest input
vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
    auto it = std::lower_bound(intervals.begin(), intervals.end(), newInterval);
    int lhs = newInterval[0], rhs = newInterval[1];
    if (it != intervals.begin() && (*(it - 1))[1] <= newInterval[0]) --it;
    while (it!= intervals.end() &&  ((*it)[1] >= lhs && (*it)[0] <= rhs)) {
        lhs = std::min((*it)[0], lhs);
        rhs = std::max((*it)[1], rhs);
        it = intervals.erase(it);
    }
    intervals.insert(it, {lhs, rhs});
    return intervals;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    auto it1 = std::lower_bound(intervals.begin(), intervals.end(), newInterval);
    int lhs = newInterval[0], rhs = newInterval[1];
    if (it1 != intervals.begin() && (*(it1 - 1))[1] <= newInterval[0]) {
        --it1;
        lhs = (*it1)[0];
    }
    auto it2 = std::upper_bound(intervals.begin(), intervals.end(), std::vector<int>{rhs, INT_MAX});
    if (it2 != intervals.begin() && (*(it2 - 1))[1] >= rhs) {
        rhs = (*(it2 - 1))[1];
    }
    auto it = intervals.erase(it1, it2);
    intervals.insert(it, {lhs, rhs});
    return intervals;
}