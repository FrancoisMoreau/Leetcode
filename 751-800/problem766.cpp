//
// Created by brayden on 2020-08-23.
//

#include "problem766.h"


using std::vector;

// my solution, too complicated, poor performance
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<std::pair<int, int>> points;
    for (int i = 0; i < m; ++i)
        points.emplace_back(i, 0);
    for (int j = 0; j < n; ++j)
        points.emplace_back(0, j);
    for (auto &elem : points) {
        int i = elem.first, j = elem.second;
        for (; i < m && j < n; ++i, ++j)
            if (matrix[i][j] != matrix[elem.first][elem.second])
                return false;
    }
    return true;
}

// 80%, 80%
bool isToEplitzMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = 0; j < matrix[0].size() - 1; ++j) {
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return false;
        }
    }
    return true;
}