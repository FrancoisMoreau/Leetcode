//
// Created by brayden on 2020-05-18.
//

#include "problem300.h"

#include <map>
using std::vector;
using std::map;

// O(n^2), time: 10%, space: 100%
int lengthOfLIS2(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> cur_longest(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                cur_longest[i] = std::max(cur_longest[i], cur_longest[j] + 1);
        }
    }
    return *std::max_element(cur_longest.begin(), cur_longest.end());
}

// O(nlogn)
// use map
int lengthOfLIS3(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
}

// O(nlogn), same thought, but hand-written binary search
int lengthOfLIS(vector<int> &nums) {
    vector<int> res(nums.size());
    int size = 0;
    for (int x : nums) {
        int i = 0, j = size;
        while (i != j) {
            int mid = (i + j) / 2;
            if (res[mid] < x) i = mid + 1;
            else j = mid;
        }
        res[i] = x;
        if (i == size) ++size;
    }
    return size;
}