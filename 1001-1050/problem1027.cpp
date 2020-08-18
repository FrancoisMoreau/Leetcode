//
// Created by brayden on 2020-08-16.
//

#include "problem1027.h"
#include <unordered_map>
#include <utility>

using std::vector;
using std::unordered_map;
using std::pair;

// 36/72 passed, TLE
void dfs(const vector<int> &A, vector<int> &path, int &cur_max, int pos) {
    if (path.size() + A.size() - pos < cur_max || A.size() == pos) return;
    for (int i = pos; i < A.size(); ++i) {
        if (path.size() + A.size() - pos < cur_max) return;
        if (path.size() > 1 && A[i] - path.back() != path.back() - path[path.size() - 2]) {
            continue;
        }
        path.push_back(A[i]);
        cur_max = std::max(cur_max, int(path.size()));
        dfs(A, path, cur_max, i + 1);
        path.pop_back();
    }
}

int longestArithSeqLength2(vector<int>& A) {
    vector<int> path;
    int cur_max = 0;
    dfs(A, path, cur_max, 0);
    return cur_max;
}

// dp, I didn't solve this problem
int longestArithSeqLength(vector<int> &A) {
    unordered_map<int, unordered_map<int, int>> dp;
    int res = 2, n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = A[j] - A[i];
            dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
            res = std::max(res, dp[d][j]);
        }
    }
    return  res;
}
