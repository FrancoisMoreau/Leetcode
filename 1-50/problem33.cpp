//
// Created by brayden on 2020-06-18.
//

#include <cmath>
#include "problem33.h"

using std::vector;

// My solution, after many times' try
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

// an simpler way, 92%, 30%
// if nums[mid] and target are "on the same side" of nums[0], we just take nums[mid], otherwise -INF, INF
int search2(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int num = nums[mid] < nums[0] == target < nums[0] ? nums[mid] : target < nums[0] ? -INFINITY : INFINITY;
        if (num < target)
            lo = mid + 1;
        else if (num > target)
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}

// another simple solutin that we can memorize
int search3(vector<int> &nums, int target) {
    int n = nums.size();
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;
        else
            hi = mid;
    }

    int min_idx = lo;
    lo = target <= nums[n - 1] ? min_idx : 0;
    hi = target > nums[n - 1] ? min_idx : n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}