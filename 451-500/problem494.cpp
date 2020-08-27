//
// Created by brayden on 2020-08-18.
//

#include "problem494.h"
#include <unordered_map>
#include <numeric>

using std::vector;
using std::unordered_map;

// 37%, 17%
int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int, int> dict;
    dict[0] = 1;
    for (int i : nums) {
        unordered_map<int, int> temp;
        for (auto &elem : dict) {
            temp[elem.first + i] += elem.second;
            temp[elem.first - i] += elem.second;
        }
        dict = temp;
    }
    return dict[S];
}

// convert to subset-sum problem
// sum(P) - sum(N) = target
// sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
//  2 * sum(P) = target + sum(nums)
// 99%, 58%
int subsetSum(vector<int> &nums, int s) {
    vector<int> dp(s  +  1);
    dp[0] = 1;
    for (int n : nums) {
        for (int i = s; i >= n; --i) {
            dp[i] += dp[i - n];
        }
    }
    return dp[s];
}

int findTargetSumWays2(vector<int> &nums, int S) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
}

// O(2^n), 6.77%, 75%
int find(int p, vector<int> &nums, int accum, int sum) {
    if (p == nums.size()) return accum == sum;
    return find(p + 1, nums, accum + nums[p], sum) + find(p + 1, nums, accum - nums[p], sum);
}

int findTargetSumways9(vector<int> &nums, int S) {
    return find(0, nums, 0, S);
}

// recursion with memoization, 20%, 10%
int find_mem(int p, vector<int> &nums, int accum, int sum, vector<unordered_map<int, int>> &memo) {
    if (p == nums.size()) return accum == sum;
    if (memo[p].find(accum) != memo[p].end())
        return memo[p][accum];
    memo[p][accum] = find_mem(p, nums, accum, sum, memo);
    return memo[p][accum];
}

int findTargetSumways8(vector<int> &nums, int S) {
    vector<unordered_map<int, int>> memo;
    return find_mem(0, nums, 0, S, memo);
}

// Dp with continuous states, 50A%, 50%
int findTargetSumways3(vector<int> &nums, int S) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (S > sum || S < -sum) return 0;
    vector<int> cur(2 * sum + 1), next(2 * sum + 1), *p_cur = &cur, *p_next = &next;
    cur[sum] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j <= 2 * sum; ++j) {
            if (p_cur->at(j)) {
                p_next->at(j + nums[i]) += p_cur->at(j);
                p_next->at(j - nums[i]) += p_cur->at(j);
            }
        }
        std::swap(p_cur, p_next);
        p_next->assign(2 * sum + 1, 0);
    }
    return p_cur->at(S + sum);
}