//
// Created by brayden on 2020-08-26.
//

#include "problem15.h"
#include <unordered_map>
#include <unordered_set>

using std::vector;

// 30%， 50%， my solution
vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    std::unordered_map<int, int> dict;
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i)
        dict[nums[i]]= i;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) break;
        for (int j = i + 1; j < n; ++j) {
            auto it = dict.find(-(nums[i] + nums[j]));
            if (it != dict.end() && it->second > j)
                res.push_back({nums[i], nums[j], nums[it->second]});
            while (j < n - 1 && nums[j] == nums[j + 1]) ++j;
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) ++i;
    }
    return res;
}

// better one, 90%, 73%
vector<vector<int>> threeSum2(vector<int> &nums) {
    vector<vector<int>> res;
    std::sort(nums.begin(), nums.end());
    if (nums.empty() || nums.front() > 0 || nums.back() < 0) return {};
    for (int i = 0; i < int(nums.size()) - 2; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int target = -nums[i];
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            if (nums[j] + nums[k] == target) {
                res.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1]) ++j;
                while (j < k && nums[k] == nums[k - 1]) --k;
                ++j, --k;
            } else if (nums[j] + nums[k] < target) ++j;
            else --k;
        }
    }
    return res;
}