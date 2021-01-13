//
// Created by brayden on 2020-10-23.
//

#include "problem403.h"
#include <set>

using std::vector;
using std::set;

// My solution, 13%, 7%
bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<set<int>> jumps(n, set<int>());
    jumps[0].insert(0);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = stones[i] - stones[j];
            if (jumps[j].empty() || diff > *(jumps[j].rbegin()) + 1) continue;
            for (int k : jumps[j]) {
                if (diff <= k + 1 && diff >= k - 1) {
                    jumps[i].insert(diff);
                }
            }
        }
    }
    return !jumps[n - 1].empty();
}

// better solution, 52%, 7%
bool canCross2(vector<int> &stones) {
    int n = stones.size();
    vector<vector<bool>> dp(n, vector<bool>(n + 1, 0));
    dp[0][1] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = stones[i] - stones[j];
            if (diff < 0 || diff > n || !dp[j][diff]) continue;
            dp[i][diff] = true;
            if (diff >= 1) dp[i][diff - 1] = true;
            if (diff <= n - 1) dp[i][diff + 1] = true;
            if (i == n - 1) return true;
        }
    }
    return false;
}


