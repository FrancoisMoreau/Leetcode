//
// Created by brayden on 2020-10-25.
//

#include "problem97.h"
#include <vector>


using std::vector;
using std::string;

bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) dp[i][j] = true;
            else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            else dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
        }
    }
    return dp[m][n];
}