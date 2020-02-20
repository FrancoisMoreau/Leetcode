#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::cout;

// #1: 3-times rotate
// using std::reverse
void rotate(vector<int> &nums, int k) {
    std::reverse(nums.begin(), nums.end() - k % nums.size());
    std::reverse(nums.end() - k % nums.size(), nums.end());
    std::reverse(nums.begin(), nums.end());
}


// #2: copy to a auxiliary array
void rotate2(vector<int> &nums, int k) {
    k = k % nums.size();
    vector<int> aux = nums;
    std::copy(aux.end() - k, aux.end(), nums.begin());
    std::copy(aux.begin(), aux.end() - k, nums.begin() + k);
}

int main() {
    //problem 189
    vector<int> nums189{1, 2, 3, 4, 5, 6, 7};
    rotate(nums189, 3);
    for (auto &i : nums189)
        printf("%d ", i);

    return 0;
}