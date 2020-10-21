//
// Created by brayden on 2020-10-15.
//

#include "two_sum_pair.h"

#include <unordered_set>

int uniquePairs(std::vector<int> nums, int target) {
    std::unordered_set<int> used, prepare_set;
    int count = 0;
    for (int num : nums) {
        if (prepare_set.find(target - num) != prepare_set.end() && used.find(num) == used.end()) {
            count++;
            used.insert(num);
            used.insert(target - num);
        } else {
            prepare_set.insert(num);
        }
    }
    return count;

}