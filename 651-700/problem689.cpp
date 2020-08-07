//
// Created by brayden on 2020-08-06.
//

#include "problem689.h"
#include <numeric>
#include <utility>

using std::vector;
using std::pair;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
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