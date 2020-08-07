//
// Created by brayden on 2020-08-06.
//

#include "problem1060.h"

using std::vector;

inline int missingcount(vector<int> &nums, int idx) {
    return nums[idx] - nums[0] - idx;
}

int missingElement(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    int count = missingcount(nums, right);

    if (k > count)
        return nums[right] + k - count;
    while (left < right) {
        int mid = left + (right - left) / 2;
        count = missingcount(nums, mid);
        if (count >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return nums[left - 1] + k - missingcount(nums, left - 1);
}