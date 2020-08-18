//
// Created by brayden on 2020-08-16.
//

#include "problem452.h"

using std::vector;

// My solution, 86%, 77%
int findMinArrowShots(vector<vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0] < rhs[0];
    });
    int lo = points[0][0], hi = points[0][1];
    int arrows = 1;
    for (int i = 1; i < points.size(); ++i) {
        if (hi >= points[i][0]) {
            lo = std::max(hi, points[i][0]);
            hi = std::min(points[i][1], hi);
        } else {
            ++arrows;
            lo = points[i][0];
            hi = points[i][1];
        }
    }
    return arrows;
}

// easier to explain
int findMinArrowShots2(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    std::sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[1] < rhs[1];
    });
    int arrowpos = points[0][1];
    int arrows = 1;
    for (int i = 1; i < points.size(); ++i) {
        if (arrowpos >= points[i][0]) continue;
        arrows++;
        arrowpos = points[i][1];
    }
    return arrows;
}