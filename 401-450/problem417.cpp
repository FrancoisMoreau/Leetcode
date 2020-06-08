//
// Created by brayden on 2020-06-08.
//

#include "problem417.h"


using std::vector;

void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col) {
    if (row < 0 || row > matrix.size() - 1 || col < 0 || col > matrix[0].size() - 1 || visited[row][col]) return ;
    visited[row][col] = true;
    if (row - 1 >= 0 && matrix[row - 1][col] >= matrix[row][col])
        dfs(matrix, visited, row - 1, col);
    if (row + 1 <= matrix.size() - 1 && matrix[row + 1][col] >= matrix[row][col])
        dfs(matrix, visited, row + 1, col);
    if (col - 1 >= 0 && matrix[row][col - 1] >= matrix[row][col])
        dfs(matrix, visited, row, col - 1);
    if (col + 1 <= matrix[0].size() - 1 && matrix[row][col + 1] >= matrix[row][col])
        dfs(matrix, visited, row, col + 1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols, 0));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, 0));
    for (int i = 0; i < cols; ++i) {
        dfs(matrix, pacific, 0, i);
        dfs(matrix, atlantic, rows - 1, i);
    }
    for (int i = 0; i < rows; ++i) {
        dfs(matrix, pacific, i, 0);
        dfs(matrix, atlantic, i, cols - 1);
    }
    vector<vector<int>> res;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }
    return res;
}