//
// Created by brayden on 2020-08-11.
//

#include "problem253.h"
#include <queue>
#include <map>

using std::vector;
using std::priority_queue;

// 98.6%, use priority_queue
int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0] < rhs[0];
    });
    priority_queue<int, vector<int>, std::greater<int>> minpq;
    minpq.push(intervals[0][1]);
//    int rooms = 1;
    for (int i = 1; i < intervals.size(); ++i) {
        if (minpq.top() <= intervals[i][0]) {
            minpq.pop();
        }
        minpq.push(intervals[i][1]);
//        rooms = std::max(rooms, int(minpq.size()));
    }
    return minpq.size();
}

// use map to add all time-points
int minMeetingRooms2(std::vector<std::vector<int>> &intervals) {
    std::map<int, int> times;
    for (auto &i : intervals) {
        ++times[i[0]];
        --times[i[1]];
    }
    int rooms = 0, res = 0;
    for (auto &it : times)
        res = std::max(res, rooms += it.second);
    return res;
}

// use 2 one-dimension arrays
int minMeetingRooms3(std::vector<std::vector<int>> &intervals) {
    vector<int> starts, ends;
    int res = 0, endpos = 0;
    for (auto a : intervals) {
        starts.push_back(a[0]);
        ends.push_back(a[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0; i < intervals.size(); ++i) {
        if (starts[i] < ends[endpos]) ++res;
        else ++endpos;
    }
    return res;
}