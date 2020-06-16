//
// Created by brayden on 2020-06-15.
//

#include "problem287.h"

using std::vector;

// This kind of problem is classic cycle problem
// can be solved by Floyd's Tortoise and Hare Algorithm
// O(n)
int findDuplicate2(vector<int>& nums) {
    if (nums.size() > 1) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    return -1;
}

// O(nlg(N)), binary search
int findDuplicate(vector<int> &nums) {
    int lo = 1, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int lower = 0;
        for (int i : nums) {
            if (i <= mid)
                ++lower;
        }
        if (lower <= mid) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}