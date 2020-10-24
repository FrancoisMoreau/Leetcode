#include <vector>
#include <queue>

using std::vector;

// brute-force, TLE
void rotate3(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    for (int i = 0; i < k; i++) {
        int prev = nums[n - 1];
        for (int j = 0; j < n; j++) {
            std::swap(prev, nums[j]);
        }
    }
}

// keep rotating
void rotate4(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    int first = 0, middle = n - k, last = n;
    int next = middle;
    while (first != next) {
        std::swap(nums[first++], nums[next++]);
        if (next == last) next = middle;
        else if (first == middle)  middle = next;
    }
}

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
