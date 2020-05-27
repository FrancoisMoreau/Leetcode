//
// Created by brayden on 2020-05-26.
//

#include "problem523.h"

#include <unordered_set>
#include <unordered_map>

using std::unordered_set;
using std::unordered_map;
using std::vector;

// My thought was totally wrong
// 30%， 5%
bool checkSubarraySum2(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    int cur_sum = 0;
    dict[0] = -1;
    for (int i = 0; i < nums.size(); ++i) {
        cur_sum = k ? (cur_sum + nums[i]) % k : (cur_sum + nums[i]);
        if (dict.find(cur_sum) != dict.end()) {
            if (i - dict[cur_sum] > 1)
                return true;
        }
        else
            dict[cur_sum] = i;
    }
    return false;
}

// using set
// No need to use map, required length is 2, so we can insert the mod one iteration later
bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_set<int> subset;
    int sum = 0, pre = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        sum = k ? sum % k : sum;
        if (subset.find(sum) != subset.end())
            return true;
        subset.emplace(pre);
        pre = sum;
    }
    return false;
}