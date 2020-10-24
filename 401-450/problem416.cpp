//
// Created by brayden on 2020-10-04.
//

#include "problem416.h"
#include <numeric>
#include <bitset>

using std::vector;

// I didn't solve this problem
// for this one: 6%, 30%
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total & 1 ) return false;
    int half = total >> 1;
    vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= half; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[n][half];
}

// 30%, 80%
bool canPartition2(vector<int> &nums) {
    int n = nums.size();
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total & 1) return false;
    int half = total >> 1;
    vector<bool> dp(half + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = half; i > 0; --i) {
            if (i >= num) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
    }
    return dp[half];
}

// backtracking, 99%, 88%
bool helper(vector<int> &nums, int sum, int idx) {
    if (idx == nums.size()) return false;
    if (sum == nums[idx]) return true;
    if (sum < nums[idx]) return false;
    return helper(nums, sum - nums[idx], idx + 1) || helper(nums, sum, idx + 1);
}

bool canPartition3(vector<int> &nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total & 1) return false;
    total /= 2;
    sort(nums.rbegin(), nums.rend());
    return helper(nums, total, 0);
}

// bitset, 92%, 88%
bool canPartition4(vector<int> &nums) {
    const int MAX_NUM = 100;
    const int MAX_ARRAY_SIZE = 200;
    std::bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
    int sum = 0;
    for (int num : nums) {
        sum += num;
        bits |= bits << num;
    }
    return !(sum % 2) && bits[sum/2];
}