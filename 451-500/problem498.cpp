//
// Created by brayden on 2020-08-17.
//

#include "problem498.h"

using std::vector;


// My solution, 90%, 40%, spent a lot of time, need to be extremely careful on the boundaries.
vector<int> findDiagonalOrder2(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    bool up = true;
    vector<int> res;
    for (int k = 0; k < m + n - 1; ++k) {
        if (up) {
            for (int i = std::min(k, m - 1); i >= 0 && k - i <= n - 1; --i)
                res.push_back(matrix[i][k - i]);
        } else {
            for (int i = std::min(k, n - 1); i >= 0 && k - i <= m - 1; --i)
                res.push_back(matrix[k - i][i]);
        }
        up = !up;
    }
    return res;
}

// no boolean, 77%, 98%
vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
    int row = 0, col = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res(m * n);
    for (int i = 0; i < m * n; ++i) {
        res[i] = matrix[row][col];
        if ((row + col) % 2 == 0) {
            if (col == n - 1) ++row;
            else if (row == 0) ++col;
            else {
                --row;
                ++col;
            }
        } else {
            if (row == m - 1) ++col;
            else if (col == 0) ++row;
            else {
                ++row;
                --col;
            }
        }
    }
    return res;
}
