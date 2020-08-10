//
// Created by brayden on 2020-08-06.
//

#include "problem689.h"
#include <numeric>
#include <utility>

using std::vector;
using std::pair;

// 46%, 20%
vector<int> maxSumOfThreeSubarrays2(vector<int>& nums, int k) {
    int n = nums.size();
    int cur = std::accumulate(nums.begin(), nums.begin() + k, 0);
    vector<int> sum_from;
    for (int i = 0; i < n - k; ++i) {
        sum_from.push_back(cur);
        cur = cur - nums[i] + nums[i + k];
    }
    sum_from.push_back(cur);
    vector<int> dp1(n - k + 1, 0), idx1(n - k + 1, 0);
    dp1[0] = sum_from[0];
    for (int i = 1; i < n - k + 1; ++i) {
        dp1[i] = std::max(dp1[i - 1], sum_from[i]);
        idx1[i] = dp1[i] == dp1[i - 1] ? idx1[i - 1] : i;
    }

    vector<int> dp2(n - 2 * k + 1, 0);
    vector<pair<int, int>> idx2(n - 2 * k + 1);
    dp2[0] = sum_from[0] + sum_from[k];
    idx2[0] = {0, k};
    for (int i = 1; i < n - 2 * k + 1; ++i) {
        dp2[i] = std::max(dp2[i - 1], dp1[i] + sum_from[i + k]);
        idx2[i] = dp2[i] == dp2[i - 1] ? idx2[i - 1] : pair<int, int>{idx1[i], i + k};
    }

    vector<int> dp3(n - 3 * k + 1, 0);
    vector<int> res{0, k, 2 * k};
    dp3[0] = sum_from[0] + sum_from[k] + sum_from[2 * k];
    for (int i = 1; i < n - 3 * k + 1; ++i) {
        dp3[i] = std::max(dp3[i - 1], dp2[i] + sum_from[i + 2 * k]);
        res = dp3[i] == dp3[i - 1] ? res : vector<int>{idx2[i].first, idx2[i].second, i + 2 * k};
    }
    return res;
}


// a more general way, 82%, 20%
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(4, vector<int>(n));
    vector<vector<int>> id(4, vector<int>(n));
    int cur = std::accumulate(nums.begin(), nums.begin() + k, 0);
    vector<int> sum_from{cur};
    for (int i = 0; i < n - k; ++i) {
        cur = cur - nums[i] + nums[i + k];
        sum_from.push_back(cur);
    }
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < n - i * k + 1; ++j) {
            if (j == 0) {
                id[i][0] = (i - 1) * k;
                for (int m = 0; m < i; ++m)
                    dp[i][j] += sum_from[m * k] ;
                continue;
            }
            dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j] + sum_from[j + (i - 1) * k]);
            id[i][j] = dp[i][j] == dp[i][j - 1] ? id[i][j - 1] : j + (i - 1) * k;
        }
    }
    vector<int> res(3);
    res[2] = id[3][n - 3 * k];
    res[1] = id[2][res[2] - 2 * k];
    res[0] = id[1][res[1] - k];
    return res;
}

// 97%, 37%
vector<int> maxSumOfThreeSubarrays3(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> accum{0};
    for (int i : nums)
        accum.push_back(accum.back() + i);
    vector<int> posLeft(n, 0), posRight(n, n - k), res(3, 0);
    for (int i = k, cur_sum = accum[k] - accum[0]; i < n; ++i) {
        if (accum[i + 1] - accum[i + 1 - k] > cur_sum) {
            posLeft[i] = i + 1 - k;
            cur_sum = accum[i + 1] - accum[i + 1 - k];
        } else {
            posLeft[i] = posLeft[i - 1];
        }
    }
    for (int i = n - k - 1, cur_sum = accum[n] - accum[n - k]; i >= 0; --i) {
        if (accum[i + k] - accum[i] >= cur_sum) {
            posRight[i] = i;
            cur_sum = accum[i + k] - accum[i];
        } else {
            posRight[i] = posRight[i + 1];
        }
    }
    // middle interval
    int maxsum = 0;
    for (int i = k; i <= n - 2 * k; ++i) {
        int l = posLeft[i - 1], r = posRight[i + k];
        int cur_sum = (accum[l + k] - accum[l]) + (accum[r + k] - accum[r]) + (accum[i + k] - accum[i]);
        if (cur_sum > maxsum) {
            maxsum = cur_sum;
            res = {l, i, r};
        }
    }
    return res;
}

