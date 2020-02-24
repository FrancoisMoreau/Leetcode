//
// Created by brayden on 2020-02-22.
//

#include "problem55.h"


// #1:greedy algorithm
// copies several month ago, forgot it at all
// here, implemented ++i each time, so this finds the possible maximum of all entries
bool canJump(vector<int>& nums) {
    int reach = 1;
    for (int i = 0; i < reach && reach < nums.size(); ++i) {
        reach = std::max(reach, i + nums[i] + 1);
    }
    return reach >= nums.size();
}

// #2: Downstairs, see if it can go to the first place
bool canJump2(vector<int> &nums) {
    int last = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (i + nums[i] > last)
            last = i;
    }
    return last == 0;
}

// #3: dynamic programming
bool canJump3(vector<int> &nums) {
    vector<int> f(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
        f[i] = std::max(f[i - 1], nums[i - 1]) - 1;
        if (f[i] < 0) return false;
    }
    return f[nums.size() - 1] >= 0;
}