//
// Created by brayden on 2020-05-25.
//

#include "problem238.h"

using std::vector;

// O(n) time, O(n) space
vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size();
    vector<int> lhs(n + 1, 1), rhs(n + 1, 1);
    for (int i = 1; i <= nums.size(); ++i) {
        lhs[i] = lhs[i - 1] * nums[i - 1];
        rhs[n - i] = rhs[n - i + 1] * nums[n - i];
    }
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        res.push_back(lhs[i] * rhs[i + 1]);
    }
    return res;
}

// O(1) space, can optimize to 1 for-loop
vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 1);
    int lhs = 1, rhs = 1;
    for (int i = 0; i < nums.size(); ++i) {
        res[i] *= lhs;
        lhs *= nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
        res[i] *= rhs;
        rhs *= nums[i];
    }
    return res;
}

