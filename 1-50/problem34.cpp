//
// Created by brayden on 2020-08-08.
//

#include "problem34.h"

using std::vector;

// use equal range
vector<int> searchRange(vector<int>& nums, int target) {

    auto res = std::equal_range(nums.cbegin(), nums.cend(), target);
    if (res.first != res.second)
        return {static_cast<int>(res.first - nums.cbegin()), static_cast<int>(res.second - nums.cbegin() - 1)};
    else
        return {-1, -1};
}


// self-written binary search
// 40%, 60%
int binary_search(const vector<int> &nums, int target, int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid;
    }
    return hi;
}

vector<int> searchRange2(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() ;
    int left = binary_search(nums, target, lo, hi);
    int right = binary_search(nums, target + 1, lo, hi);
    if (left == right) return {-1, -1};
    else return {left, right - 1};
}