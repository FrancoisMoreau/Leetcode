//
// Created by brayden on 2020-06-10.
//

#include "problem128.h"
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;


// I didn't solve this problem
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> dict;
    int max = 0;
    for (int i : nums) {
        if (dict.find(i) == dict.end()) {
            dict[i] = dict[i - 1] + dict[i + 1] + 1;
            max = std::max(dict[i], max);
            dict[i - dict[i - 1]] = dict[i];
            dict[i + dict[ i + 1]] = dict[i];
        }
    }
    return max;
}

// another solution
int longestConsecutive2(vector<int> &nums) {
    unordered_set<int> dict(nums.begin(), nums.end());
    int max = 0;
    for (int i : nums) {
        if (dict.find(i) == dict.end()) continue;
        dict.erase(i);
        int prev = i - 1, next = i + 1;
        while (dict.find(prev) != dict.end()) dict.erase(prev--);
        while (dict.find(next) != dict.end()) dict.erase(next++);
        max = std::max(max, next - prev - 1);
    }
    return max;
}