//
// Created by brayden on 2020-06-08.
//

#include "problem75.h"

using std::vector;

// 3 way quick sort, I totally forgot it!
void sortColors(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    int i = lo;
    while (i <= hi) {
        if (nums[i] < 1) std::swap(nums[i++], nums[lo++]);
        else if (nums[i] > 1) std::swap(nums[i], nums[hi--]);
        else ++i;
    }
}

// use bucket sort
// copy_n: Copies the first n elements from the range beginning at first into the range beginning at result.
// Copies the elements in the range [first,last) into the range beginning at result.
void sortColors2(vector<int> &nums) {
    vector<int> bucket(3);
    for (int i : nums)
        bucket[i]++;
    std::fill_n(nums.begin(), bucket[0], 0);
    std::fill_n(nums.begin() + bucket[0],bucket[1], 1);
    std::fill_n(nums.begin() + bucket[0] + bucket[1], bucket[2], 2);
}