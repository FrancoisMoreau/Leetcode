#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cout;
using std::endl;

// problem 27: Remove Element
// #1: using std::remove, may use erase or not
// this is called erase-remove idiom
int removeElement(vector<int> &nums, int val) {
    auto new_end = std::remove(nums.begin(), nums.end(), val);
    return std::distance(nums.begin(), new_end);
}

// #2: one way search, erase
int removeElement2(vector<int> &nums, int val) {
    int n = nums.size();
    auto itr = nums.begin();
    for (int i = 0; i < n; ++i) {
        if (*itr == val)
            itr = nums.erase(itr);
        else
            itr++;
    }
    return nums.size();
}

// #3: one way copy
int removeElement3(vector<int> &nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val)
            nums[index++] = nums[i];
    }
    return index;
}
