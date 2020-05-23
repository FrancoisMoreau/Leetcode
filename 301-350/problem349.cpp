//
// Created by brayden on 2020-05-18.
//

#include "problem349.h"

#include <set>
#include <unordered_set>

using std::set;
using std::vector;
using std::unordered_set;

// my solution
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
    vector<int> out;
    for (auto it = set1.cbegin(); it != set1.cend(); ++it) {
        if (set2.find(*it) != set2.end())
            out.push_back(*it);
    }
    return out;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (int x : nums2) {
        if (m.erase(x))
            res.push_back(x);
    }
    return res;
}
