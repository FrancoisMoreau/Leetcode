//
// Created by brayden on 2020-05-22.
//

#include <algorithm>
#include <vector>
#include "problem887.h"

using std::vector;

// Time Limit Exceeded
// My brute force solution: k * n^2
int superEggDrop0(int K, int N) {
    vector<vector<int>> dp(K + 1, std::vector<int>(N + 1, 1));
    for (int i = 1; i <= N; ++i) dp[1][i] = i;

    for (int i = 2; i <= K; ++i) {
        for (int j = 2; j <= N; ++j) {
            int cur_min = INT_MAX;
            for (int k = 1; k < j; ++k) {
                cur_min = std::min(cur_min, std::max(dp[i - 1][k], dp[i][j - k - 1]) + 1);
            }
            dp[i][j] = cur_min;
        }
    }
    return dp[K][N];
}

// we can use binary search for k, k*nlogn
// 47%, 15%
int dfs(int i, int j, vector<vector<int>> &dp) {
    if (i == 1) return j;
    if (j == 0) return 0;
    if (j == 1) return 1;
    if (dp[i][j]) return dp[i][j];
    int lo = 0, hi = j;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int lhs = dfs(i - 1, mid - 1, dp);
        int rhs = dfs(i, j - mid, dp);
        if (lhs < rhs) lo = mid + 1;
        else hi = mid;
    }
    dp[i][j] = std::max(dfs(i - 1, lo - 1, dp), dfs(i, j - lo, dp)) + 1;
    return dp[i][j];
}

int superEggDrop4(int K, int N) {
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    return dfs(K, N, dp);
}

// optimize the above solution's binary search, to K * N
// 51%, 15%
int superEggDrop6(int K, int N) {
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    for (int i = 0; i <= K; ++i) dp[i][1] = 1;
    for (int i = 0; i <= N; ++i) dp[1][i] = i;
    for (int i = 2; i <= K; ++i) {
        int k = 1;
        for (int j =  2; j <= N; ++j) {
            while (k < j + 1 && dp[i][j - k] > dp[i - 1][k - 1])
                ++k;
            dp[i][j] = 1 + dp[i - 1][k - 1];
        }
    }
    return dp[K][N];
}

// we can optimize the space above, to N
// 55%, 77%
int superEggDrop2(int K, int N) {
    vector<int> dp(N + 1), pre_dp(N + 1);
    vector<int> tmp(N + 1, INT_MAX);
    tmp[0] = 0, tmp[1] = 1;
    for (int i = 1; i <= N; ++i) pre_dp[i] = i;
    for (int i = 2; i <= K; ++i) {
        int k = 1;
        dp = tmp;
        for (int j = 2; j <= N; ++j) {
            while (k < j + 1 && dp[j - k]  > pre_dp[k - 1]) ++k;
            dp[j] = pre_dp[k - 1] + 1;
        }
        pre_dp = dp;
    }
    return dp[N];
}

// Most fancy solution, O(KlogN), O(NK) space
// dp equation: dp
int superEggDrop3(int K, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    int m = 0;
    while (dp[m][K] < N) {
        ++m;
        for (int k = 1; k <= K; ++k)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    return m ;
}

// 100%, 100%
// KlogN time, O(K) space
int superEggDrop(int K, int N) {
    vector<int> dp(K + 1, 0);
    int m;
    for (m = 0; dp[K] < N; ++m) {
        for (int k = K; k > 0; --k)
            dp[k] += dp[k - 1] + 1;
    }
    return m;
}
