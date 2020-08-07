//
// Created by brayden on 2020-08-06.
//

#ifndef INC_351_400_PROBLEM398_H
#define INC_351_400_PROBLEM398_H

#include <vector>
#include <unordered_map>

// My solution, refered problem 528
// performance: 20%, 40%
class Solution398 {
public:
    Solution398 (std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (dict.find(nums[i]) == dict.end()) {
                dict[nums[i]] = {i};
            } else {
                dict[nums[i]].push_back(i);
            }
        }
    }

    int pick(int target) {
        int cur_size = dict[target].size();
        int r = rand() % cur_size;
        return dict[target][r];
    }
private:
    std::unordered_map<int, std::vector<int>> dict;
};


#endif //INC_351_400_PROBLEM398_H
