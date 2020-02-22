//
// Created by brayden on 2020-02-21.
//

#include "problem220.h"

#include <set>
using std::set;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> cand;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) cand.erase(nums[i - k - 1]);
        auto lower = cand.lower_bound(nums[i] - t);
        auto higher = cand.upper_bound(nums[i] + t);
        if (higher  != lower) return true;
        cand.insert(nums[i]);
    }
    return false;
}
