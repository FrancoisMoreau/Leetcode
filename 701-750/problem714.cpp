//
// Created by brayden on 2020-10-27.
//

#include "problem714.h"



int maxProfit(std::vector<int>& prices, int fee) {
    int cur_min = prices[0], cur_max = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] + fee < cur_max) {
            profit += std::max(cur_max - cur_min - fee, 0);
            cur_min = prices[i];
            cur_max = prices[i];
        } else {
            cur_min = std::min(cur_min, prices[i]);
            cur_max = std::max(cur_max, prices[i]);
        }
    }
    profit += std::max(cur_max - cur_min -fee, 0);
    return profit;
}