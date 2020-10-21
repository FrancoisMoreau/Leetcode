//
// Created by brayden on 2020-10-02.
//

#include "problem322.h"


int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin < 0) continue;
            if (dp[i - coin] == -1) continue;
            else {
                if (dp[i] == -1)
                    dp[i] = dp[i - coin] + 1;
                else
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount];

}