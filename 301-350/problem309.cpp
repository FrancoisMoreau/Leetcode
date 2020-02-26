//
// Created by brayden on 2020-02-24.
//

#include "problem309.h"

int maxProfit_cooldown(vector<int>& prices) {
    if (prices.size() < 2) return 0;
//    vector<int> dp(prices.size(), 0);
    vector<int> dp(3, 0);
    vector<int> prev_min(prices.size(), 0);
    dp[1] = std::max(0, prices[1] - prices[0]);
    prev_min[0] = prices[0], prev_min[1] = std::min(prices[0], prices[1]);
    for (int i = 2; i < prices.size(); ++i) {
        prev_min[i] = std::min(prev_min[i - 1], prices[i] - dp[(i - 2) % 3]);
        dp[i % 3] = std::max(dp[(i - 1) % 3 ], prices[i] - prev_min[i]);
    }
//    for (int i : dp)
//        printf("%d, ", i);
//    printf("\n");
    return dp[(prices.size() - 1) % 3];
}