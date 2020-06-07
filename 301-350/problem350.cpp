//
// Created by brayden on 2020-06-05.
//

#include "problem350.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_multiset;

// Time(nlogn), not so good
// 20%, 5%
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_multiset<int> set1(nums1.begin(), nums1.end());
    std::unordered_map<int, int> dict;
    for (auto i : nums2) {
        ++dict[i];
    }
    vector<int> res;
    for (auto &i : dict) {
        int cnt = set1.erase(i.first);
        res.insert(res.end(), std::min(cnt, i.second), i.first);
    }
    return res;
}

//using sort, 90%, 53%, all stl, fast
vector<int> intersect2(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    nums1.erase(std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
    return nums1;
}

// Hash table solution, 90%, 5%
// O(m + n)
vector<int> intersect3(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_map<int, int> dict;
    vector<int> res;
    for (int i : nums1)
        ++dict[i];
    for (int j : nums2) {
        if (--dict[j] >= 0)
            res.push_back(j);
    }
    return res;
}

//using sort, then 2 pointers, 90%, 50%
vector<int> intersect4(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            ++i;
            ++j;
        } else if (nums1[i] < nums2[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    return res;
}