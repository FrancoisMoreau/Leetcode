//
// Created by brayden on 2020-05-23.
//

#include "problem410.h"
#include <numeric>

using std::vector;

// dp[m][k] = min(dp[m - 1][n - k], sum(k, n))
// My solution: dp,  O(m * n ^2),  36%, 100%
int splitArray2(vector<int>& nums, int m) {
    int n = nums.size();
    vector<long> prev(n + 1), cur(n + 1);
    for (int i = 0; i < n; ++i) {
        prev[i + 1] = prev[i] + nums[i];
    }
    vector<long> con = prev;

    for (int j = 2; j <= m; ++j) {
        for (int k = 1; k <= n; ++k) {
            long cur_min = INT_MAX;
            for (int l = 0; l <= k; ++l) {
                cur_min = std::min(cur_min, std::max(prev[l], long(con[k] - con[l])));
            }
            cur[k] = cur_min;
        }
        prev = cur;
    }
    return prev[n];
}

// Greedy + binary search
// nlogn, fast. 60%, 100%
bool isvalid(const vector<int> &nums, int cuts, long max) {
    int acc = 0;
    for (auto num : nums) {
        if (num > max) return false;
        else if (acc + num <= max) acc += num;
        else {
            --cuts;
            acc = num;
            if (cuts < 0) return false;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    long lhs = 0, rhs = 0;
    for (auto i : nums) {
        lhs = std::max(lhs, long(i));
        rhs += i;
    }
    while (lhs < rhs ) {
        long mid = (lhs + rhs ) / 2;
        if (isvalid(nums, m - 1, mid)) rhs = mid;
        else lhs = mid + 1;
    }
    return lhs;
}

