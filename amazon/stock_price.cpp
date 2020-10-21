//
// Created by brayden on 2020-10-15.
//

#include "stock_price.h"
#include <deque>

std::vector<int> min_stock_price(std::vector<int> stockpricedelta, int windowsize) {
    std::deque<int> dq;
    std::vector<int> res;
    for (int i = 0; i < stockpricedelta.size(); i++) {
        if (!dq.empty() && dq.front() < i - windowsize + 1) dq.pop_front();
        while (!dq.empty() && stockpricedelta[dq.back()] > stockpricedelta[i])
            dq.pop_back();
        dq.push_back(i);
        if (i - windowsize + 1 >= 0) res.push_back(stockpricedelta[dq.front()]);
    }
    return res;
}