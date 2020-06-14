//
// Created by brayden on 2020-06-11.
//

#include "problem240.h"
#include <utility>

using std::pair;
using std::vector;

// My poor binary search solution, 600 ms
bool subsearch(vector<vector<int>> &matrix, int target, pair<int, int> left_top, pair<int, int> right_bottom) {
    if (left_top.first > right_bottom.first || left_top.second > right_bottom.second) return false;
    int horizon_mid = left_top.first + (right_bottom.first - left_top.first ) / 2;
    int vertical_mid = left_top.second + (right_bottom.second - left_top.second) / 2;
    if (matrix[horizon_mid][vertical_mid] < target) {
        return subsearch(matrix, target, {horizon_mid + 1, left_top.second}, right_bottom)
        || subsearch(matrix, target, {left_top.first, vertical_mid + 1}, {horizon_mid, right_bottom.second});
    } else if (matrix[horizon_mid][vertical_mid] > target) {
        return subsearch(matrix, target, left_top, {horizon_mid - 1, right_bottom.second})
        || subsearch(matrix, target, {horizon_mid, left_top.second}, {right_bottom.first, vertical_mid - 1});
    } else {
        return true;
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size() - 1, n = matrix[0].size() - 1;
    return subsearch(matrix, target, {0, 0}, {m, n});
}

// concise solution from top right, 100ms, 90% faster
bool searchMatrix2(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n  -1;
    while (i < m && j >= 0) {
        if (matrix[i][j] < target) ++i;
        else if (matrix[i][j] > target) --j;
        else return true;
    }
    return false;
}