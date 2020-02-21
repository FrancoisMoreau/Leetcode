//
// Created by brayden on 2020-02-20.
//

#include "problem274.h"
#include <numeric>
//problem 274
// #1. by sort, O(nlgn)
//can use hash, but use more space
int hIndex(vector<int>& citations) {
    std::sort(citations.begin(), citations.end());
    int n = citations.size();
//    int cur_h = 0;
    for (int i = 0; i < n; ++i) {
//        cur_h = std::max(cur_h, std::min(n - i, citations[i]));
        if (citations[i] >= n - i) return n - i;
    }
    return 0;
}

//bucket sort, O(n), no extra space. Great algorithm
// think as this, as n is the total number of papers, so at most : N

int hIndex2(vector<int>& citations) {
    int n = citations.size();
    vector<int> buckets(n + 1, 0);
    for (auto i : citations) {
        if (i >= n) ++buckets[n];
        else ++buckets[i];
    }

    //have to iterate from right
    int hindex = 0;
    for (int i = n; i >= 0; --i) {
        hindex += buckets[i];
        if (hindex >= i) return i;
    }
    return 0;
}