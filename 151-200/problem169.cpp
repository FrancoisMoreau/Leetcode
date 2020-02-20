//
// Created by brayden on 2020-02-20.
//

#include "problem169.h"
#include <unordered_map>
#include <algorithm>

//paradigm solutions
// #1: solve by a partial sort, using stl nth_element
int majorityElement_p1(vector<int> &nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}

// #2:  hash, simple way
int majorityElement_p2(vector<int> &nums) {
    std::unordered_map<int, int> counter;
    for (int num : nums) {
        if (++counter[num] > nums.size() / 2)
            return num;
    }
    return 0;
}

//#3: bit manipulation
// the main idea: if the number of a bit is set more than half, then it's set in final res

//#4: 


// Followings are my answer, it seems that I made a mistake
//using hash

int majorityElement(vector<int>& nums) {
    std::unordered_map<int, int> times;
    for (auto &i : nums)
        times[i]++;
    int idx = nums[0];
    int freq = times[idx];
    for (auto it = times.cbegin(); it != times.cend(); ++it) {
        if (it->second > freq) {
            idx = it->first;
            freq = it->second;
        }
    }
    return idx;
}

//using equal_range
int majorityElement2(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto start = nums.begin(), max_idx = nums.begin();
    int max_freq = 0;
    while (start != nums.end()) {
        auto cur_end = std::upper_bound(nums.begin(), nums.end(), *start);
        if (std::distance(start, cur_end) > max_freq) {
            max_idx = start;
            max_freq = std::distance(start, cur_end);
        }
        start = cur_end;
    }
    return *max_idx;
}
