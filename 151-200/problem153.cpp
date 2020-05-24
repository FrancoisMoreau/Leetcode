//
// Created by brayden on 2020-05-23.
//

#include "problem153.h"

using std::vector;

int binaysearch(vector<int> &nums, int lo, int hi) {
    int mid = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else {
            if (mid > 0 && nums[mid - 1] > nums[mid])
                return mid;
            else
                hi = mid - 1;
        }
    }
    return lo;
}

int findMin2(vector<int>& nums) {
    int mid = binaysearch(nums, 0, nums.size() - 1);
    return nums[mid];
}

int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        if (nums[lo] < nums[hi]) return nums[lo];
        int mid = (lo + hi) / 2;
        if (nums[mid] >= nums[lo])
            lo = mid + 1;
        else
            hi = mid;
    }
    return  nums[lo];
}