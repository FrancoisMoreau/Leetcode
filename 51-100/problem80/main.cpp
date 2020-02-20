#include <iostream>
#include <vector>

using std::vector;


//problem 80: Remove Duplicates from Sorted Array II
// using std::upper_bound
int removeDuplicatesII(vector<int>& nums) {
    auto p_itr = nums.begin(), begin = nums.begin(), upper_beg = begin;

    while (begin != nums.end()) {
        *p_itr++ = *begin;
        upper_beg = std::upper_bound(begin, nums.end(), *begin);
        if (upper_beg - begin > 1)
            *p_itr++ = *(begin + 1);
        begin = upper_beg;
    }
    return p_itr - nums.begin();
}

// one way copy, using an index
int removeDuplicatesII2(vector<int> &nums) {
    if (nums.size() <= 2) return nums.size();
    int index = 2;
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];
    }
    return index;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}