//
// Created by brayden on 2020-02-24.
//

#include "problem164.h"

int maximumGap(vector<int>& nums) {
    int cur_min = INT_MAX, cur_max = INT_MIN;
    int max_difference = 0;
    for (int i : nums) {
        cur_min = std::min(cur_min, i);
        cur_max = std::max(cur_max, i);
        max_difference = std::max(std::max(max_difference, i - cur_min), cur_max - i);
    }
    return max_difference;
}