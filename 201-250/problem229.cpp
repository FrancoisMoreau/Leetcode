//
// Created by brayden on 2020-02-20.
//

#include "problem229.h"

// run in linear time and O(1) space
// it's necessary to count the number of 2 candidates, and check if their value is bigger than n/3

vector<int> majorityElement(vector<int>& nums) {
//    if (nums.size() < 2) return nums;
    int count_lhs = 0, maj_lhs(0);
    int count_rhs = 0, maj_rhs(0);
    for (auto i : nums) {
        if (!count_lhs) maj_lhs = i;
        if (!count_rhs) maj_rhs = i;
        if (maj_lhs == maj_rhs) {
            maj_rhs = i;
        }
        if (maj_lhs == i) {
            count_lhs += 1;
        } else if (maj_rhs == i) {
            count_rhs += 1;
        } else{
            count_lhs -= 1;
            count_rhs -= 1;
        }
    }
    count_lhs = 0, count_rhs = 0;

    for (auto i : nums) {
        if (i == maj_lhs) ++count_lhs;
        else if (i == maj_rhs) ++count_rhs;
    }
    vector<int> res;
    if (count_lhs > nums.size() / 3) res.push_back(maj_lhs);
    if (count_rhs > nums.size() / 3) res.push_back(maj_rhs);

    return res;
}