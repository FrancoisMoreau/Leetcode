//
// Created by brayden on 2019-09-27.
//

#include "RotatedArraySearch.h"
#include <stdio.h>
#include <algorithm>

int RotatedArraySearch::find_pivot(std::vector<int> &nums, int left, int right) {
    if (left >= right)
        return left;
    int mid = (left + right) / 2;
    if (nums[mid] > nums[mid + 1])
        return mid;
    else if (nums[mid] < nums[std::max(mid - 1, 0)])
        return mid - 1;
    else {
        if (nums[mid] > nums[right])
            return find_pivot(nums, mid + 1, right);
        else
            return find_pivot(nums, left, std::max(mid - 1, 0));
    }
}

int RotatedArraySearch::search2(std::vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int n = nums.size() - 1;
    int pivot =  find_pivot(nums, 0, n);
    auto range0 = std::equal_range(nums.cbegin(), nums.cbegin() + pivot + 1, target);
    if (range0.first != range0.second)
        return (range0.first - nums.begin());
    auto range1 = std::equal_range(nums.begin() + pivot + 1, nums.end(), target);
    if (range1.first != range1.second)
        return (range1.first - nums.begin());
    return -1;
}

int RotatedArraySearch::search(std::vector<int> &nums, int target) {
    int first = 0, last = nums.size() ;
    while (first < last) {
        const int mid = (first + last) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[first] <= nums[mid]) {
            if (nums[first] <= target && target < nums[mid])
                last = mid;
            else
                first = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[last - 1])
                first = mid + 1;
            else
                last = mid;
        }
    }
    return -1;
}

