//
// Created by brayden on 2020-08-21.
//

#include "problem1269.h"
#include <vector>
#include <cmath>

using std::vector;

// My solution, 12%, 43%, time: O(steps^2), space: O(steps^2)
int subfind(int steps, int cur_pos, int arrLen, vector<vector<int>> &dp) {
    if (dp[steps][cur_pos] != -1) return dp[steps][cur_pos];
    long cur_sum = subfind(steps - 1, cur_pos, arrLen, dp);
    if (cur_pos > 0) cur_sum += subfind(steps - 1, cur_pos - 1, arrLen, dp);
    if (cur_pos < arrLen - 1) cur_sum += subfind(steps - 1, cur_pos + 1, arrLen, dp);
    dp[steps][cur_pos] = cur_sum % (long(pow(10, 9)) + 7);
    return dp[steps][cur_pos];
}

int numWays2(int steps, int arrLen) {
    if (arrLen > steps) arrLen = steps;
    vector<vector<int>> dp(steps + 1, vector<int>(arrLen, -1));
//    vector<vector<int>> dp(steps / 2 + 1, vector<int>(steps + 1, -1));
    dp[0] = vector<int>(arrLen, 0);
    dp[0][0] = 1;
    return subfind(steps, 0, arrLen, dp);
}

// bottom-up dp, 20%, 20%
int numWays3(int steps, int arrLen) {
    int maxPos = std::min(steps, arrLen);
    vector<vector<long>> dp(steps + 1, vector<long>(maxPos + 1));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= steps; ++i) {
        for (int j = 0; j < maxPos; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1] + (j > 0 ? dp[i - 1][j - 1] : 0)) % (1000000007);
        }
    }
    return dp[steps][0];
}

// 92%, 96%
int numWays(int steps, int arrLen) {
    int sz = std::min(steps / 2 + 1, arrLen);
    vector<int> v1(sz + 2), v2(sz + 2);
    v1[1] = 1;
    while (steps-- > 0) {
        for (auto i = 1; i <= sz; ++i)
            v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
        swap(v1, v2);
    }
    return v1[1];
}