//
// Created by brayden on 2020-02-23.
//

#include "problem188.h"

int simple_maxProfit(vector<int> &prices);

int maxProfit_ktran(int k, vector<int>& prices) {
    if (prices.empty()) return 0;
    if (k >= prices.size() / 2) return simple_maxProfit(prices);
    vector<int> dp(k + 1, 0);
    vector<int> min(k + 1, prices[0]);
    for (int i = 1; i < prices.size(); ++i) {
        for (int j = 1; j <= k; ++j) {
            min[j] = std::min(min[j], prices[i] - dp[j - 1]);
            dp[j] = std::max(dp[j], prices[i] - min[j]);
        }
    }
    return dp[k];
}

int simple_maxProfit(vector<int> &prices) {
    int sum = 0;
    for (int i = 1; i < prices.size(); ++i) {
        sum += std::max(prices[i] - prices[i - 1], 0);
    }
    return sum;
}