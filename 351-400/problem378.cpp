//
// Created by brayden on 2020-05-15.
//

#include "problem378.h"

#include <tuple>
#include <queue>

using std::vector;
using std::tuple;
using std::priority_queue;

//(row, col, val)
typedef tuple<int, int, int> threeD;

// priority queue
int kthSmallest2(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    auto cmp = [](const threeD &lhs, const threeD &rhs) {
        return std::get<2>(lhs)  > std::get<2>(rhs);
    };
//    printf("n: %d\n", n);
    priority_queue<threeD, vector<threeD>, decltype(cmp)> minpq(cmp);
    for (int i = 0; i < n; ++i)
        minpq.push(std::make_tuple(0, i, matrix[0][i]));
    for (int i = 0; i < k - 1; ++i) {
        threeD cur = minpq.top();
        minpq.pop();
        if (std::get<0>(cur) == n - 1) continue;
        minpq.emplace(std::make_tuple(std::get<0>(cur) + 1, std::get<1>(cur), matrix[std::get<0>(cur) + 1][std::get<1>(cur)]));
    }
    return std::get<2>(minpq.top());
}



int kthSmallest3(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[2] > rhs[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minpq(cmp);
    for (int i = 0; i < n; ++i)
        minpq.push({0, i, matrix[0][i]});
    for (int i = 0; i < k - 1; ++i) {
        if (minpq.top()[0] == n - 1) {
            minpq.pop();
            continue;
        } else {
            minpq.emplace(vector<int>{minpq.top()[0] + 1, minpq.top()[1], matrix[minpq.top()[0] + 1][minpq.top()[1]]});
            minpq.pop();
        }
    }
    return minpq.top()[2];

}

// binary search
int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int count = 0, j = n - 1;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && matrix[i][j] > mid) --j;
            count += (j + 1);
        }
        if (count < k) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}