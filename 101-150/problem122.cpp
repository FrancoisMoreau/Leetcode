//
// Created by brayden on 2020-02-22.
//

#include "problem122.h"

int maxProfitII(vector<int>& prices) {
	int max_sum = 0;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] > prices[i - 1]) {
			max_sum += prices[i] - prices[i - 1];
		}
	}
	return max_sum;
}