#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) return {{}};
    vector<vector<int>> res{{nums[0]}};

    for (int i = 1; i < nums.size(); ++i) {
        int n = res[0].size();
        int cur_size = res.size();
        res.resize(cur_size * (n + 1));

        for (int j = 0; j < n; ++j) {
            std::copy(res.begin(), res.begin() + cur_size , res.begin() + cur_size *(j + 1));
        }
        for (int j = 0; j < n + 1; ++j) {
            for (int k = 0; k < cur_size; ++k) {
                res[j * cur_size + k].insert(res[j * cur_size + k].begin() + j, nums[i]);
            }
        }
    }
    return res;
}

vector<vector<int>> permute2(vector<int> &nums) {
    if (nums.empty()) return {{}};
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    do {
        ans.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    return ans;
}

void permute_dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, int idx) {
    if (idx == nums.size()) {
        res.push_back(path);
        return;
    }
    for (auto &i : nums) {
        auto found = std::find(path.begin(), path.end(), i);
        if (found == path.end()) {
            path.push_back(i);
            permute_dfs(res, path, nums, idx + 1);
            path.pop_back();
        }
    }
}

vector<vector<int>> permute3(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> path;

    permute_dfs(ans, path, nums, 0);
    return ans;
}


int main() {
    vector<int> input{1, 2, 3};
    vector<vector<int>> ans = permute3(input);

    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}