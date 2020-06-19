//
// Created by brayden on 2020-06-18.
//

#include "problem33.h"

using std::vector;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) {
            if (nums[mid] >= nums[lo] || nums[lo] > target)
                lo = mid + 1;
            else
                hi = mid - 1;

        } else if (nums[mid] > target) {
            if (nums[mid] < nums[hi] || nums[hi] < target)
                hi = mid - 1;
            else
                lo = mid + 1;

        } else
            return mid;
    }
    return -1;
}