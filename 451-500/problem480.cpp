//
// Created by brayden on 2020-08-17.
//

#include "problem480.h"
#include <set>

using std::vector;
using std::set;
using std::multiset;

// 13%, 58%
int getmedian(multiset<int>::iterator it, int k) {
    std::advance(it, k);
    return *it;
}

vector<double> medianSlidingWindow2(vector<int>& nums, int k) {
    bool isodd = k % 2;
    vector<double> res;
    multiset<int> myset(nums.begin(), nums.begin() + k - 1);
    for (int i = k - 1; i < nums.size(); ++i) {
        myset.insert(nums[i]);
        if (isodd) res.push_back(getmedian(myset.begin(), k / 2));
        else res.push_back(getmedian(myset.begin(), k / 2) / 2.0 + getmedian(myset.begin(), k / 2 - 1) / 2.0);
        auto it = myset.find(nums[i - k + 1]);

        myset.erase(it);
    }
    return res;
}

// use the same idea, but keep an iterator which points to median always
// 88%,75%
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = std::next(window.begin(), k / 2);
    vector<double > res;
    for (int i = k; ; ++i) {
        res.push_back(((double)(*mid) + *std::prev(mid, 1 - k % 2)) / 2);
        if (i == nums.size())
            return res;
        window.insert(nums[i]);
        if (nums[i] < *mid) --mid;
        if (nums[i - k] <= *mid) ++mid;
        window.erase(window.lower_bound(nums[i - k]));
    }
}