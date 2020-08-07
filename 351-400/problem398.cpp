//
// Created by brayden on 2020-08-06.
//

#include "problem398.h"


#include <vector>
#include <random>

// 30%, 50%
class Solution {
public:
    Solution(std::vector<int> nums) {
        _nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = -1;
        for (int i = 0; i < _nums.size(); ++i) {
            if (_nums[i] != target) continue;
            if (n == 0) {
                ans = i;
                n++;
            } else {
                n++;
                if (rand() % n == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }

private:
    std::vector<int> _nums;
};

// or
class Solution3 {
public:
    Solution3(std::vector<int> num) {
        _nums = num;
    }

    int pick(int target) {
        int count = 0, idx = -1;
        for (int i = 0; i < _nums.size(); ++i) {
            if (_nums[i] == target) {
                std::mt19937 e{std::random_device{}()};
                std::uniform_int_distribution<unsigned > u(0, count++);
//                static std::default_random_engine e;
//                std::uniform_int_distribution<unsigned > u(0, count++);
                if (!u(e)) {
                    idx = i;
                }
            }
        }
        return idx;
    }

private:
    std::vector<int> _nums;
};