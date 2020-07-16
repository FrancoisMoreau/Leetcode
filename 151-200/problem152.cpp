//
// Created by brayden on 2020-06-22.
//

#include "problem152.h"
#include <utility>

using std::vector;
using std::pair;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    int prev_min = 1, prev_max = 1;
    int cur_max = INT32_MIN;
    for (int num : nums) {
        if (num == 0) {
            prev_max = prev_min = 1;
            cur_max = std::max(cur_max, 0);
        }
        prev_min *= num;
        prev_max *= num;
        int tmp = prev_max;
        prev_max = std::max(std::max(prev_max, prev_min), num);
        prev_min = std::min(std::min(tmp, prev_min), num);
        cur_max = std::max(prev_max, cur_max);
    }
    return cur_max;
}

int maxProduct2(vector<int> &nums) {
    int prev_max = nums[0], prev_min = nums[0];
    int cur_max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0)
            std::swap(prev_max, prev_min);
        prev_max = std::max(prev_max * nums[i], nums[i]);
        prev_min = std::min(prev_min * nums[i], nums[i]);
        cur_max = std::max(cur_max, prev_max);
    }
    return cur_max;
}

// another magic implementation
int maxProduct3(vector<int> &nums) {
    int n = nums.size(), res = nums[0], l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        l = (l ? l : 1) * nums[i];
        r = (r ? r : 1) * nums[n - 1 - i];
        res = std::max(res, std::max(l, r));
    }
    return  res;
}