//
// Created by brayden on 2020-08-11.
//

#include "problem252.h"
#include <set>

using std::set;
using std::vector;

bool canAttendMeetings(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) return true;
    set<vector<int>> inset(intervals.begin(), intervals.end());
    auto prev = inset.begin();
    for (auto it = ++inset.begin(); it != inset.end(); ++it) {
        if ((*prev)[1] > (*it)[0])
            return false;
    }
    return true;
}