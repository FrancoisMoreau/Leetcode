//
// Created by brayden on 2020-02-22.
//

#include "problem121.h"

// #way1, concise
int maxProfit(vector<int>& prices) {
	int max = 0, lowest = prices[0];
	for (auto i : prices) {
		lowest = std::min(lowest, i);
		max = std::max(max, i - lowest);
	}
	return max;
}

// the solution above could be optimized,
// don't need to update the lowest and max value every time
/* java implementation
public int maxProfit(int[] prices) {
    if(prices == null || prices.length < 2) return 0;      
    int maxProfit = 0, minPrice = prices[0];
    
    for(int i = 1; i < prices.length; i++) {
        if(prices[i] > prices[i - 1]) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);       
        } else {
             minPrice = Math.min(minPrice, prices[i]);
        }
    }

    return maxProfit;
}
*/

// #2: similar to maximum subarray, very useful dynamic programming
// calculate the difference: maxCur += prices[i] - prices[i-1], if the difference falls below 0, reset it to 0
// This is called Kadane's Algorithm
int maxProfit2(std::vector<int> &prices) {
	int maxCur = 0, maxSoFar = 0;
	for (int i = 1; i < prices.size(); ++i) {
		maxCur = std::max(0, maxCur += prices[i] - prices[i - 1]);
		maxSoFar = std::max(maxCur, maxSoFar);
	}
	return maxSoFar;
}


