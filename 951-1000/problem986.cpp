//
// Created by brayden on 2020-08-03.
//

#include "problem986.h"

using std::vector;

// 90%, 98%
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int lhs = 0, rhs = 0;
    vector<vector<int>> res;
    while (lhs < A.size() && rhs < B.size()) {
        int left = std::max(A[lhs][0], B[rhs][0]);
        int right = std::min(A[lhs][1], B[rhs][1]);
        if (left <= right)
            res.push_back({left, right});
        if (A[lhs][1] > B[rhs][1])
            ++rhs;
        else
            ++lhs;
    }
    return res;
}