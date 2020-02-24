//
// Created by brayden on 2020-02-22.
//

#include <algorithm>
#include "problem123.h"

// #1: dynamic programming
// dp[k, i] = max(dp[k, i - 1], prices[i] - prices[j] + dp[k - 1, j - 1]), j = [0, ..., i - 1]

// in this solution: time: O(kn^2), space: O(kn);
int maxProfitIII(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
    for (int k = 1; k <= 2; ++k) {
        for (int i = 1; i < prices.size(); ++i) {
            int min = prices[0];
            for (int j = 1; j <= i; ++j) {
                min = std::min(min, prices[j] - dp[k - 1][j - 1]);
            }
            dp[k][i] = std::max(dp[k][i - 1], prices[i] - min);
        }
    }
    return dp[2][prices.size() - 1];
}

//the code above could be optimized:
// now: time: O(kn), space: O(kn);
int maxProfitIII2(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
    for (int k = 1; k <= 2; ++k) {
        int min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min = std::min(min, prices[i] - dp[k - 1][i - 1]);
            dp[k][i] = std::max(dp[k][i - 1], prices[i] - min);
        }
    }
    return dp[2][prices.size() - 1];
}

//slightly swap the two "for" loops
int maxProfitIII2_5(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
    vector<int> min(3, prices[0]);
    for (int i = 1; i < prices.size(); ++i) {
        for (int k = 1; k <=2; ++k) {
            min[k] =  std::min(min[k], prices[i] - dp[k - 1][i - 1]);
            dp[k][i] = std::max(dp[k][i - 1], prices[i] - min[k]);
        }
    }
    return dp[2][prices.size() - 1];
}

// as dp[k][i] only depends on dp[k][i-1], so we can compact second dimension
int maxProfitIII3(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> dp(3, 0);
    vector<int> min(3, prices[0]);
    for (int i = 1; i < prices.size(); ++i) {
        for (int k = 1; k <= 2; ++k) {
            min[k] = std::min(min[k], prices[i] - dp[k - 1]);
            dp[k] = std::max(dp[k], prices[i] - min[k]);
        }
    }
    return dp[2];
}

