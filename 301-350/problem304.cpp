//
// Created by brayden on 2020-08-10.
//

#include "problem304.h"

// 61%, 14%
NumMatrix::NumMatrix(std::vector<std::vector<int>> &matrix) : accu(matrix.size(), std::vector<int>{0}){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 1; j <= matrix[0].size(); ++j) {
            accu[i].push_back(accu[i].back() + matrix[i][j - 1]);
        }
    }
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
    int res = 0;
    for (int i = row1; i <= row2; ++i) {
        res += accu[i][col2 + 1] - accu[i][col1];
    }
    return res;
}
