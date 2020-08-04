//
// Created by brayden on 2020-08-03.
//

#include "problem31.h"

using std::vector;

// 100%, 42.5%
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1;
    for (; i > 0; --i) {
        if (nums[i] > nums[i - 1])
            break;
    }
    if (i > 0) {
        int cur_min = i;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] > nums[i - 1] && nums[j] < nums[cur_min])
                cur_min = j;
        }
        std::swap(nums[i - 1], nums[cur_min]);
        std::sort(nums.begin() + i, nums.end());
    } else {
        std::sort(nums.begin(), nums.end());
    }
}

// can also be simplified as
// We don't need 2 sorts above because it's already sorted, we only need to reverse
// also, to find the smallest value bigger than nums[i], also we can use the condition that it's already sorted
void nextPermutation2(vector<int>& nums) {
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--) {
        if (nums[k] < nums[k + 1]) {
            break;
        }
    }
    if (k < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        for (l = n - 1; l > k; l--) {
            if (nums[l] > nums[k]) {
                break;
            }
        }
        std::swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}