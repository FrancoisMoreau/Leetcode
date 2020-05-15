//
// Created by brayden on 2020-05-15.
//

#include "problem215.h"

using std::vector;

// partial sort/ nth_element
int findKthLargest(vector<int>& nums, int k) {
    std::partial_sort(nums.begin(), nums.end(), nums.begin() + k,
            [](int lhs, int rhs) {
        return lhs > rhs;
    });
    return nums[k - 1];
}

