//
// Created by brayden on 2020-06-14.
//

#include "problem329.h"

using std::vector;

// dfs, 85%, 60%
int dfs_findpath(vector<vector<int>> &matrix, vector<vector<int>> &len_matrix, int row, int col) {
    if (len_matrix[row][col]) return len_matrix[row][col];
    int cur_max = 1;
    if (row > 0 && matrix[row - 1][col] > matrix[row][col])
        cur_max = std::max(cur_max, 1 + dfs_findpath(matrix, len_matrix, row - 1, col));
    if (row < matrix.size() - 1 && matrix[row + 1][col] > matrix[row][col])
        cur_max = std::max(cur_max, 1 + dfs_findpath(matrix, len_matrix, row + 1, col));
    if (col > 0 && matrix[row][col - 1] > matrix[row][col])
        cur_max = std::max(cur_max, 1 + dfs_findpath(matrix, len_matrix, row, col - 1));
    if (col < matrix[0].size() - 1 && matrix[row][col + 1] > matrix[row][col])
        cur_max = std::max(1 + dfs_findpath(matrix, len_matrix, row, col + 1), cur_max);
    len_matrix[row][col] = cur_max;
    return cur_max;

}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int max_len = 1;
    vector<vector<int>> len_maxtrix(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            max_len = std::max(max_len, dfs_findpath(matrix, len_maxtrix, i, j));
        }
    }
    return max_len;
}