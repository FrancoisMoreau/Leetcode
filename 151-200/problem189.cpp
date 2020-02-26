#include <vector>
#include <queue>

using std::vector;

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
