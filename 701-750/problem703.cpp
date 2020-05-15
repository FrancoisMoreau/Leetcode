//
// Created by brayden on 2020-05-15.
//

#include "problem703.h"

KthLargest::KthLargest(int k, std::vector<int> &nums) : K(k) {
    for (auto i : nums) {
        minpq.push(i);
        if (minpq.size() > K)
            minpq.pop();
    }
}

int KthLargest::add(int val) {
    minpq.push(val);
    if (minpq.size() > K)
        minpq.pop();
    return minpq.top();
}