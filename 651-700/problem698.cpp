//
// Created by brayden on 2020-06-11.
//

#include "problem698.h"
#include <numeric>

using std::vector;

// DFS, 80%, 70%
bool dfs_find(vector<int> &nums, int cur_sum, int to_use, int target, int idx) {
    if (to_use == 1) return true;
    if (cur_sum == target) return dfs_find(nums, 0, to_use - 1, target, 0);
    if (idx >= nums.size() || cur_sum > target) return false;
    for (int i = idx; i < nums.size(); ++i) {
        if (!nums[i]) continue;
        int tmp = nums[i];
        cur_sum += nums[i];
        nums[i] = 0;
        if (dfs_find(nums, cur_sum, to_use, target, i))
            return true;
        nums[i] = tmp;
        cur_sum -= tmp;
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    return dfs_find(nums, 0, k, sum / k, 0);
}

// dynamic programming + bit manipulation
// dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
// 30%, 10%
bool canPartitionKSubsets2(vector<int> &nums, int k) {
    int n = nums.size(), sum = 0;
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) sum += nums[i];
    if (sum % k) return false;
    int target = sum / k;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == -1) continue;
        for (int i = 0; i < n; ++i) {
            if (!(mask&(1 << i)) && dp[mask] + nums[i] <= target) {
                dp[mask| 1 << i] = (dp[mask] + nums[i]) % target;
            }
        }
    }
    return dp[(1<<n)-1] == 0;
}