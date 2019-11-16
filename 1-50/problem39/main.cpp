#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;


void depth_search(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int left, int right, int diff) {
    if (diff == 0) {
        res.push_back(path);
        return;
    }
    for (int idx = left; idx < right; ++idx) {
        if (candidates[idx] > diff) return;
        path.push_back(candidates[idx]);
        depth_search(res, path, candidates, idx, right, diff - candidates[idx]);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    depth_search(res, path, candidates, 0, candidates.size(), target);

    return res;
}

int main() {
    vector<int> candidate{2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidate, target);
    for (auto &i : ans) {
        for (auto &j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}