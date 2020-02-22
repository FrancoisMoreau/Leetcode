//
// Created by brayden on 2020-02-21.
//

#include "problem219.h"

#include <unordered_map>
#include <set>
using std::unordered_map;
using std::set;
// #use hash here
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); ++i) {
        if (dict.find(nums[i]) != dict.end() && i - dict[nums[i]] <= k)
            return true;
        dict[nums[i]] = i;
    }
    return false;
}

// #use set
bool containsNearbyDuplicate2(vector<int>& nums, int k) {
    set<int> cand;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) cand.erase(nums[i-k-1]);
        if (!cand.insert(nums[i]).second) return true;
    }
    return false;
}
