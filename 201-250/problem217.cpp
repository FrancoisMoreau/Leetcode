//
// Created by brayden on 2020-02-21.
//

#include "problem217.h"

#include <algorithm>
#include <unordered_set>

// #1. using set
// unordered_set is fasted, I didn't come up with this
// not so familiar with stl container transitions
bool containsDuplicate(vector<int>& nums) {
    return  nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
}
// #2: soring

// #3: hash
