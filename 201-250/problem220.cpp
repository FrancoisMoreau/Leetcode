//
// Created by brayden on 2020-02-21.
//

#include "problem220.h"

#include <set>
#include <unordered_map>
using std::unordered_map;
using std::set;


// O(NlogN), as a tree is introduced here
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//    if (t < 0) return false;
    set<long> cand;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) cand.erase(nums[i - k - 1]);
        auto lower = cand.lower_bound(long(nums[i]) - t);
        if (lower != cand.end() && *lower - nums[i] <= t) return true;
        // better than find the upper_bound
//        auto higher = cand.upper_bound(long(nums[i]) + t);
//        if (higher  != lower) return true;
        cand.insert(nums[i]);
    }
    return false;
}

// #2: O(N), using buckets
bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
    if (t < 0 || k < 1) return false;
    unordered_map<long, long> bucket;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) bucket.erase((long(nums[i - k - 1]) - INT_MIN) / ((long)t + 1));
        long id = (long(nums[i]) - INT_MIN) / ((long)t + 1);
        if (bucket.count(id) || (bucket.count(id -1 ) && nums[i] - bucket[id - 1] <= t) ||
                (bucket.count(id + 1) && bucket[id + 1] - nums[i] <= t)) return true;
        bucket[id] = nums[i];
    }
    return false;
}
