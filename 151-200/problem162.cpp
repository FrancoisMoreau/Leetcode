//
// Created by brayden on 2020-06-03.
//

#include "problem162.h"

using std::vector;

// Explanation:
//Lets say you have a mid number at index x, nums[x]
//if (num[x+1] > nums[x]), that means a peak element HAS to exist on the right half
// of that array, because (since every number is unique) 1. the numbers keep increasing
// on the right side, and the peak will be the last element. 2. the numbers stop increasing
// and there is a 'dip', or there exists somewhere a number such that nums[y] < nums[y-1],
// which means number[x] is a peak element.
//
//This same logic can be applied to the left hand side (nums[x] < nums[x-1]).

// O(n), Not so good solution
int findPeakElement100(vector<int>& nums) {
    if (nums.size() == 1 || nums[0] > nums[1]) return 0;
    int n = nums.size();
    if (nums[n - 1] > nums[n - 2]) return n - 1;
    for (int i = 1; i < n - 1; ++i) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
    }
    return 0;
}

// O(lgN), iterative binary search
int findPeakElement(vector<int> &nums) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] < nums[mid + 1]) i = mid + 1;
        else j = mid;
    }
    return i;
}

// sequential search
int findPeakElement2(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1])
            return i - 1;
    }
    return nums.size() - 1;
}
