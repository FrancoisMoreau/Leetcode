//
// Created by brayden on 2020-06-02.
//

#include "problem528.h"

#include <vector>

//my thought was totally wrong!
// When it comes to random, must use rand function
class Solution528 {
public:
    Solution528(std::vector<int>& w) : vec(&w) {

    }
    int pickIndex() {
        if (cur_weight >= (*vec)[cur_idx]) {
            ++cur_idx;
            cur_weight = 0;
        }
        if (cur_idx >= vec->size()) {
            initialize();
        }
        ++cur_weight;
        return cur_idx;
    }

private:
    void initialize() {
        cur_idx = 0;
        cur_weight = 0;
    }
    std::vector<int> *vec;
    int cur_idx = 0;
    int cur_weight = 0;
};


// Correct solution!!!

class Solution {
public:
    Solution(std::vector<int> &w) {
        for (int i : w)
            vec.push_back(vec.empty()? i : i + vec.back());
    }

    int pickIndex() {
        int m = vec.back();
        int r = rand() % m + 1;
        // notice that here we need to plus 1 to get the range [1, 14]
        // and the binary search below deal with the range search..
        // w = {2, 5, 3, 4} => vec = {2, 7, 10, 14},
        // it search {1, 2}, {3, 7}, {8, 10}, {11, 14}
        int lhs = 0, rhs = vec.size() - 1;
        while (lhs < rhs) {
            int mid = lhs + (rhs - lhs) / 2;
            if (vec[mid] == r)
                return mid;
            else if (vec[mid] < r)
                lhs = mid + 1;
            else
                rhs = mid;
        }
        return lhs;
    }

    // if we use upper_bound here
    int pickIndex2() {
        int m = vec.back();
        int r = rand() % m;
        auto it = upper_bound(vec.begin(), vec.end(), r);
        return it - vec.begin();
    }

private:
    std::vector<int> vec;

};