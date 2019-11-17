#include <iostream>
#include <vector>

using std::vector;


void inner_combinae(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates, int left, int diff) {
    if (diff == 0) {
        res.push_back(path);
        return ;
    }
    for (int idx = left; idx < candidates.size(); ++idx) {
        if (candidates[idx] > diff) return;
        path.push_back(candidates[idx]);
        int n = 1;
        inner_combinae(res, path, candidates, idx + n, diff - candidates[idx]);
        path.pop_back();
        while (idx < candidates.size() - 1 && candidates[idx] == candidates[idx + 1]) ++idx;
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    inner_combinae(res, path, candidates, 0, target);
    return res;
}

int main() {
    vector<int> input{10,1,2,7,6,1,5};
    vector<vector<int>> ans = combinationSum2(input, 8);
    for (auto &i : ans) {
        for (auto &j : i)
            std::cout << j << " ";
        printf("\n");
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}