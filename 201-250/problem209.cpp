//
// Created by brayden on 2020-05-18.
//

#include "problem209.h"
#include <algorithm>

using std::vector;

// O(n)
int minSubArrayLen(int s, vector<int>& nums) {
    int cur_min = INT_MAX;
    int i = 0, j = 0;
    int cur_sum = 0;
    while (j < nums.size()) {
        cur_sum += nums[j];
        while (cur_sum >= s) {
            cur_min = std::min(cur_min, j - i + 1);
            cur_sum -= nums[i];
            ++i;
        }
        ++j;
    }
    return cur_min == INT_MAX ? 0 : cur_min;
}

// O(nlogn)
int minSubArrayLen2(int s, vector<int> &nums) {
    int n = nums.size(), cur_min = INT_MAX;
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = n; i >= 0 && sums[i] >= s; --i) {
        int j = std::distance(sums.begin(), std::upper_bound(sums.begin(), sums.end(), sums[i] - s));
        cur_min = std::min(cur_min, i -j + 1);
    }
    return cur_min == INT_MAX ? 0 : cur_min;
}