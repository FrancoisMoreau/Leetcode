//
// Created by brayden on 2020-06-05.
//

#include "problem78.h"

using std::vector;

// iteration, 100%, 72%
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({});
    for (int i : nums) {
        int cur_size = res.size();
        res.resize(2 * cur_size);
        std::copy_n(res.begin(), cur_size, res.begin() + cur_size);
        for (auto it = res.begin() + cur_size; it != res.end(); ++it){
            (*it).push_back(i);
        }
    }
    return res;
}

// recursion + backtracking
void construct(vector<vector<int>> &res, vector<int> &nums, vector<int> &cur_path, int idx) {
    res.push_back(cur_path);
    for (int i = idx; i < nums.size(); ++i) {
        cur_path.push_back(nums[i]);
        construct(res, nums, cur_path, i + 1);
        cur_path.pop_back();
    }
}

vector<vector<int>> subsets2(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> cur_path;
    construct(res, nums, cur_path, 0);
    return res;
}

// bit manipulation
vector<vector<int>> subsets3(vector<int>& nums) {
    int n = nums.size(), p = 1 << n;
    vector<vector<int>> subs(p);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                subs[i].push_back(nums[j]);
            }
        }
    }
    return subs;
}