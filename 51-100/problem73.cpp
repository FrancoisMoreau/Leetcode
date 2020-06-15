//
// Created by brayden on 2020-06-14.
//

#include "problem73.h"

using std::vector;

// My solution, uses space O(m + n)
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> zero_rows, zeros_cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!matrix[i][j]) {
                zero_rows.push_back(i);
                zeros_cols.push_back(cols);
            }
        }
    }
    for (int row : zero_rows)
        matrix[row] = vector<int>(cols, 0);
    for (int col : zeros_cols) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][col] = 0;
        }
    }
}

// another solutions, uses O(1) space
void setZeros2(vector<vector<int>> &matrix) {
    if (matrix.empty()) return;
    int rows = matrix.size(), cols = matrix[0].size();

    int col0 = 1;
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for (int i = rows - 1; i >= 0; --i) {
        for (int j = cols - 1; j >= 1; --j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col0 == 0) matrix[i][0] = 0;
    }
}