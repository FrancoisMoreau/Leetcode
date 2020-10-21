//
// Created by brayden on 2020-10-15.
//

#include "problem221.h"


using std::vector;

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int maxi = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!i || !j || matrix[i][j] == '0') {
                dp[i][j] = matrix[i][j] - '0';
            } else {
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
            maxi = std::max(maxi, dp[i][j]);
        }
    }
    return maxi * maxi;
}