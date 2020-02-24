#include <iostream>
#include <vector>

using std::vector;

int jump(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 1) return 0;
    int idx = 0, jump_times = 1;
    while (idx + nums[idx] < n - 1) {
        ++jump_times;
        int max_range = 0, max_idx = 0;
        for (int i = idx + 1; i <= idx + nums[idx]; ++i) {
            if (i + nums[i] > max_range) {
                max_idx = i;
                max_range = i + nums[i];
            }
            if (max_range >= n) break;
        }
        idx = max_idx;
    }
    return jump_times;
}

int jump2(vector<int> &nums) {
    int steps = 0, max_range = 0, prev_range = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (prev_range >= nums.size() - 1) return steps;
        if (i > prev_range) {
            ++steps;
            prev_range = max_range;
        }
        max_range = std::max(max_range, i + nums[i]);
    }
    return steps;
}


int main() {
    std::vector<int> v{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    // std::vector<int> v{2, 3, 1, 1, 4};
    std::cout << jump2(v) << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}