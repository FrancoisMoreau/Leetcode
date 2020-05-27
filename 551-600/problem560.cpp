//
// Created by brayden on 2020-05-25.
//

#include "problem560.h"
#include <unordered_map>

using std::unordered_map;
using std::vector;

// My solution
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    int cur = 0, res = 0;
    dict[0] = 1;
    for (auto i : nums) {
        cur += i;
        if (dict.find(cur - k) != dict.end()) {
            res += dict[cur - k];
        }
        ++dict[cur];
    }
    return res;
}