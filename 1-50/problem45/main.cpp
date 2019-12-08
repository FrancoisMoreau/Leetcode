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


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}