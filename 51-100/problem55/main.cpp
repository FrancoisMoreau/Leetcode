#include <iostream>
#include <vector>

using std::vector;

bool canJump(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 1) return true;
    int idx = 0;
    while (idx + nums[idx] < n - 1) {
        int max_range = 0, max_idx = 0;
        if (nums[idx] == 0) return false;
        for (int i = idx + 1; i <= idx + nums[idx]; ++i) {
            if (i + nums[i] > max_range) {
                max_idx = i;
                max_range = i + nums[i];
            }
            if (max_range >= n) break;
        }
        idx = max_idx;
    }
    return true;
}

bool canJump2(const vector<int> &nums) {
    int reach = 1;
    for (int i = 0; i < reach && reach < nums.size(); ++i) {
        reach = std::max(reach, static_cast<int>(i + 1 + nums[i]));
    }
    return reach >=  nums.size();
}

bool canJump3(const vector<int> &nums) {
    const int n = nums.size();
    vector<int> f(n, 0);
    f[0] = 0;
    for (int i = 1 ; i < n; ++i) {
        f[i] = std::max(f[i - 1], nums[i - 1]) - 1;
        if (f[i] < 0) return false;
    }
    return f[n - 1] >= 0;
}

int main() {


    std::cout << "Hello, World!" << std::endl;
    return 0;
}