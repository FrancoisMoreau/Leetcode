//
// Created by brayden on 2020-06-16.
//

#include "problem63.h"

using std::vector;

// TLE
void dfs_path(vector<vector<int>> &obstacleGrid, int row, int col, int &count) {
    if (row >= obstacleGrid.size() || col >= obstacleGrid[0].size() || obstacleGrid[row][col] == 1) return;
    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1) {
        ++count;
        return;
    }
    dfs_path(obstacleGrid, row + 1, col, count);
    dfs_path(obstacleGrid, row, col + 1, count);

}

int uniquePathsWithObstacles100(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;
    int count = 0;
    dfs_path(obstacleGrid, 0, 0, count);
    return count;
}

// dp, My solutionm, 30%, 30%
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;
    int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 1));
    for (int i = 0; i < rows; ++i) {
        if (obstacleGrid[i][0]) {
            while (i < rows)
                dp[i++][0] = 0;
            break;
        }
    }
    for (int j = 0; j < cols; ++j) {
        if (obstacleGrid[0][j]) {
            std::fill(dp[0].begin() + j, dp[0].end(), 0);
            break;
        }
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (obstacleGrid[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

// dp, less code, 90%, 15%
int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // Nice idea on this!
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!obstacleGrid[i - 1][j - 1])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

// dp, O(n) space
int uniquePathWithObstacles3(vector<vector<int>> &obstacleGrid) {
    int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
    vector<int> dp(cols, 0);
    dp[0] = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (obstacleGrid[i][j])
                dp[j] = 0;
            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp[cols - 1];
}