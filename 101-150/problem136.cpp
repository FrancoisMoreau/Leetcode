//
// Created by brayden on 2020-06-22.
//

#include "problem136.h"

using std::vector;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i : nums)
        res ^= i;
    return res;
}