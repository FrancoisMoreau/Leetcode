//
// Created by brayden on 2020-05-13.
//

#include "problem347.h"

#include <map>
#include <unordered_map>

using std::map;
using std::multimap;

// 1st: map, flip
template <typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &p) {
    return std::pair<B, A>(p.second, p.first);
}

template <typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B> &src) {
    multimap<B, A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A, B>);
    return dst;
}

// using map then flip, time: 32%, space: 6%
vector<int> topKFrequent2(vector<int>& nums, int k) {
    map<int, int> freq;
    for (auto i : nums)
        ++freq[i];
    // why I don't need <A, B> here? look it up!
    multimap<int, int> sorted = flip_map(freq);
    vector<int> res;
    int i = 0;
    for (auto it = sorted.crbegin(); i < k; ++i, ++it) {
        res.push_back(it->second);
    }
    return res;
}

// 2nd: map, then vector<pair>, sort with quick-select
auto cmp = [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return lhs.second > rhs.second;
};

int partition(vector<std::pair<int, int>> &vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (cmp(vec[++i], vec[lo]))
            if (i == hi) break;
        while (cmp(vec[lo], vec[--j]))
            if (j == lo) break;
        if (j <= i) break;
        std::swap(vec[i], vec[j]);
    }
    std::swap(vec[lo], vec[j]);
    return j;
}


vector<int> topKFrequent3(vector<int> &nums, int k) {
    std::unordered_map<int, int> freq;
    for (auto i : nums)
        ++freq[i];
    vector<std::pair<int, int>> fq_vec;
    fq_vec.reserve(freq.size());

    for (auto &i : freq)
        fq_vec.emplace_back(i.first, i.second);
    int lo = 0, hi = fq_vec.size() - 1;

    while (lo < hi) {
        int j = partition(fq_vec, lo, hi);
        if (j < k) lo = j + 1;
        else if (j > k) hi = j - 1;
        else break;
    }
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(fq_vec[i].first);
    }
    return res;
}

// 3: bucket sort
vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    for (int num : nums)
        ++m[num];

    vector<vector<int>> buckets(nums.size() + 1);
    for (auto p : m)
        buckets[p.second].push_back(p.first);

    vector<int> ans;
    for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
        for (int num : buckets[i]) {
            ans.push_back(num);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}