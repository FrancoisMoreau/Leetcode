//
// Created by brayden on 2020-05-25.
//

#include "problem560.h"
#include <unordered_map>

using std::unordered_map;
using std::vector;

// brute force: TLE
// O(n^3) time complexity, O(1) space complexity

// cumulative sum, O(n^2) for time, O(n) for space
int subarraysum3(vector<int> &nums, int k) {
    int count = 0;
    vector<int> sum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i)
        sum[i] = sum[i - 1] + nums[i - 1];
    for (int start = 0; start < nums.size(); ++start) {
        for (int end = start + 1; end <= nums.size(); ++end) {
            if (sum[end] - sum[start] == k)
                ++count;
        }
    }
    return count;
}

// without space, O(n^2) for time, O(n) for space
int subarraysum4(vector<int> &nums, int k) {
    int count = 0;
    for (int start = 0; start < nums.size(); ++start) {
        int sum = 0;
        for (int end = start; end < nums.size(); ++end) {
            sum += nums[end];
            if (sum == k)
                ++count;
        }
    }
    return count;
}



// My solution
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    int cur = 0, res = 0;
    dict[0] = 1;
    for (auto i : nums) {
        cur += i;
        if (dict.find(cur - k) != dict.end()) {
            res += dict[cur - k];
        }
        ++dict[cur];
    }
    return res;
}

// July 24, 2020
// if (presum.find(cur - k) != presum.end()) is faster than if (presum[cur - k])
// remember to use map here
int subarraySum2(vector<int>& nums, int k) {
    unordered_map<int, int> presum;
    int cur = 0, count = 0;
    for (int i : nums) {
        presum[cur] += 1;
        cur += i;
        if (presum.find(cur - k) != presum.end())
            count += presum[cur - k];
    }
    return count;
}