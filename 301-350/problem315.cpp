//
// Created by brayden on 2020-05-18.
//

#include "problem315.h"

#include <set>
using std::multiset;
using std::vector;
using std::pair;


// Time Limit Exceeded
vector<int> countSmaller2(vector<int>& nums) {
    multiset<int> seq;
    vector<int> res(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        res[i] = std::distance(seq.begin(), seq.lower_bound(nums[i]));
        seq.emplace(nums[i]);
    }
    return res;
}

// However, I found this code could pass
vector<int> countSmaller3(vector<int> &nums) {
    vector<int> sfx, ret(nums.size());
    for(int i = nums.size() - 1; i >= 0; --i) {
        auto it = lower_bound(sfx.begin(), sfx.end(), nums[i]);
        ret[i] = it - sfx.begin();
        sfx.insert(it, nums[i]);
    }
    return ret;
}

// Using Merge Sort
void countSmallerMerge(vector<int> &nums, vector<int> &idx, vector<int> &res, int lo, int mid, int hi, vector<int> &aux) {
    std::copy(idx.begin() + lo, idx.begin() + hi + 1, aux.begin() + lo);

    int counts = 0;
    int i = lo, j = lo, k = mid + 1;
    while (i <= hi) {
        if (j > mid) idx[i++] = aux[k++];
        else if (k > hi) {
            res[aux[j]] += counts;
            idx[i++] = aux[j++];
        } else if (nums[aux[k]] < nums[aux[j]]) {
            idx[i++] = aux[k++];
            ++counts;
        } else {
            res[aux[j]] += counts;
            idx[i++] = aux[j++];
        }
    }
}


void countSmaller(vector<int> &nums, vector<int> &idx, vector<int> &res, int lo, int hi, vector<int> &aux) {
    if (lo >= hi) return ;
    int mid = lo + (hi - lo) / 2;
    countSmaller(nums, idx, res, lo, mid, aux);
    countSmaller(nums, idx, res, mid + 1, hi, aux);
    countSmallerMerge(nums, idx, res, lo, mid, hi, aux);
}

vector<int> countSmaller(vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;
    vector<int> res(nums.size(), 0), aux(nums.size()), idx;
    for (int i = 0; i <= hi; ++i)
        idx.push_back(i);
    countSmaller(nums, idx, res, lo, hi, aux);
    return res;
}

// Merge sort by using C++ built-ins
void sort_count(vector<pair<int,int>> &hold, int lo, int hi, vector<int> &count) {
    if (hi - lo <= 1) return;
    int mid = (lo + hi) / 2;
    sort_count(hold, lo, mid, count);
    sort_count(hold, mid, hi, count);
    for (int i = lo, j = mid; i < mid; ++i) {
        while (j < hi && hold[i].first > hold[j].first ) ++j;
        count[hold[i].second] += j - mid;
    }
    std::inplace_merge(hold.begin() + lo, hold.begin() + mid, hold.begin() + hi);

}

vector<int> countSmaller4(vector<int> &nums) {
    vector<pair<int, int>> hold;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        hold.push_back({nums[i], i});
    }
    vector<int> count(n, 0);
    sort_count(hold, 0, n, count);
    return count;
}


// can also be solved by Binary Indexed Trees/ Segment Tree
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76611/Short-Java-Binary-Index-Tree-BEAT-97.33-With-Detailed-Explanation