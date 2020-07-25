//
// Created by brayden on 2020-05-13.
//

#include "problem973.h"

#include <algorithm>
#include <queue>
#include <set>
using std::vector;


// STL, use partial_sort/nth_element, O(nlogK)
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    std::partial_sort(points.begin(), points.begin() + K, points.end(),
            [](const vector<int> &lhs, const vector<int> &rhs) {
        return (lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1]);
    });
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

// Quick select, time: 90% faster
bool comp(const vector<int> &lhs, const vector<int> &rhs) {
    return lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1];
}

int partition(vector<vector<int>> &points, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (comp(points[++i], points[lo]))
            if (i == hi) break;
        while (comp(points[lo], points[--j]))
            if (j == lo) break;
        if (i >= j) break;
        std::swap(points[i], points[j]);
    }
    std::swap(points[lo], points[j]);
    return j;
}
std::vector<std::vector<int>> kClosest2(std::vector<std::vector<int>>& points, int K) {
    int lo = 0, hi = points.size() - 1;
    while (hi > lo) {
        int j = partition(points, lo, hi);
        if (j < K) lo = j + 1;
        else if (j > K) hi = j - 1;
        else return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

// priority queue, I never use this before!
// Maxheap: O(nlogK), Minheap: O(n + Klogn)
auto minpq_cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
    return lhs[0] * lhs[0] + lhs[1] * lhs[1] > rhs[0] * rhs[0] + rhs[1] * rhs[1];
};

std::vector<std::vector<int>> kClosest3(std::vector<std::vector<int>>& points, int K) {
    std::priority_queue<vector<int>, vector<vector<int>>, decltype(minpq_cmp)> minpq(points.begin(), points.end());
    vector<vector<int>> res;
    for (int i = 0; i < K; ++i) {
        res.push_back(minpq.top());
        minpq.pop();
    }
    return res;
}

// Max/min heaps can also be implemented by using multiset
vector<vector<int>> kClosest4(vector<vector<int>>& points, int K) {
    std::multiset<vector<int>, decltype(minpq_cmp)> mset;
    for (vector<int>& point : points) {
        mset.insert(point);
        if (mset.size() > K) {
            mset.erase(mset.begin());
        }
    }
    vector<vector<int>> ans;
    copy_n(mset.begin(), K, back_inserter(ans));
    return ans;
}

// implement quicksort here!
int QuickPartition(vector<int> &vec, int lo, int hi) {
    int i = lo, j = hi + 1;
    while (true) {
        while (vec[++i] < vec[lo]) {
            if (i == hi)
                break;
        }
        while (vec[--j] > vec[lo]) {
            if (j == lo)
                break;
        }
        if (i >= j) break;
        std::swap(vec[i], vec[j]);
    }
    std::swap(vec[lo], vec[j]);
    return j;
}

void QuickSort(vector<int> &vec, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = QuickPartition(vec, lo, hi);
    QuickSort(vec, lo, j - 1);
    QuickSort(vec, j + 1, hi);
}

