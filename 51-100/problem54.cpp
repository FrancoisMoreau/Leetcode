//
// Created by brayden on 2020-06-14.
//

#include "problem54.h"

using std::vector;

// My solution, 10%, 20%
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    vector<int> res;
    while (left <= right && top <= bottom) {
//        res.insert(res.end(),  matrix[top].begin() + left, matrix[top].begin() + right + 1);
        for (int i = left; i <= right; ++i)
            res.push_back(matrix[top][i]);
        ++top;
        if (top > bottom) break;
        for (int i = top; i <= bottom; ++i)
            res.push_back(matrix[i][right]);
        --right;
        if (left > right) break;
        for (int i = right; i >= left; --i)
            res.push_back(matrix[bottom][i]);
        --bottom;
        if (top > bottom) break;
        for (int i = bottom; i >= top; --i)
            res.push_back(matrix[i][left]);
        ++left;
    }
    return res;
}

// Direction based, 0 ms, 100%
vector<int> spiralOrder2(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> steps{cols, rows - 1};
    int i_dir = 0;
    int i_row = 0, i_col = -1;
    vector<int> res;
    while (steps[i_dir % 2]) {
        for (int i = 0; i < steps[i_dir % 2]; ++i) {
            i_row += directions[i_dir][0];
            i_col += directions[i_dir][1];
            res.push_back(matrix[i_row][i_col]);
        }
        steps[i_dir % 2]--;
        i_dir = (i_dir + 1) % 4;
    }
    return res;
}