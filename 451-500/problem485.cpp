//
// Created by brayden on 2020-10-25.
//

#include "problem485.h"



int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int cur = 0, max = 0;
    bool prev = false;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            cur = 0;
            prev = false;
        } else {
            prev = true;
            cur = prev ? cur + 1 : 1;
            max = std::max(max, cur);
        }
    }
    return max;
}

//simpler
int findMaxConsecutiveOnes2(std::vector<int>& nums) {
    int cur = 0, max = 0;
    for (int i : nums) {
        cur = i == 1 ? cur + 1 : 0;
        max = std::max(max, cur);
    }
    return max;
}