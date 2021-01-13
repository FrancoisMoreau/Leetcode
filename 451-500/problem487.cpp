//
// Created by brayden on 2020-10-25.
//

#include "problem487.h"

using std::vector;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int max = 0, n = nums.size();
    int first = 0, second = 0;
    int count0 = 0;
    while (first < n) {
        if (nums[first] == 0) count0++;
        while (count0 > 1) {
            if (nums[second++] == 0) count0--;
        }
        max = std::max(first - second + 1, max);
        first++;
    }
    return max;
    // write your code here
}