//
// Created by brayden on 2020-06-22.
//

#include "problem283.h"

using std::vector;

// 99%, 30%
void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    for (i = 0; i < nums.size(); ++i) {
        if (!nums[i])
            break;
    }
    j = i;
    while (j < nums.size()) {
        if (nums[j]) {
            nums[i++] = nums[j];
        }
        ++j;
    }
    while (i < nums.size())
        nums[i++] = 0;
}

// less code, 99%, 60%
void moveZeros3(vector<int> &nums) {
    int j = 0;
    // move all the nonzero elements advance
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for (;j < nums.size(); j++) {
        nums[j] = 0;
    }
}

// Snowball
void moveZeros4(vector<int> &nums) {
    int snowball = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) ++snowball;
        else if (snowball > 0) {
            std::swap(nums[i], nums[i - snowball]);
        }
    }
}

// 53%, 70%
void moveZeros2(vector<int> &nums) {
    auto it = std::remove(nums.begin(), nums.end(), 0);
    while (it < nums.end())
        *(it++) = 0;
}