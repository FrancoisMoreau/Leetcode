//
// Created by brayden on 2020-06-16.
//

#include "problem81.h"

using std::vector;

bool search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) return true;

        if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
            --hi;
            ++lo;
        } else if (nums[mid] < target) {
            if (nums[mid] >= nums[lo] || nums[lo] > target)
                lo = mid + 1;
            else
                hi = mid - 1;
        } else {
            if (nums[mid] <= nums[hi] || nums[hi] < target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    return false;
}

bool search2(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return true;
        int num = nums[mid] < nums[lo] == target < nums[lo] ? nums[mid] : target < nums[lo] ? INT_MIN : INT_MAX;
        if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
            --hi;
            ++lo;
        } else if (num < target) lo = mid + 1;
        else hi = mid;
    }
    return false;
}