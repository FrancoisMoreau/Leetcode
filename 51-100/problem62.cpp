//
// Created by brayden on 2020-06-14.
//

#include "problem62.h"
#include <vector>

using std::vector;

// My solution, dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
// O(m * n) time, O(m * n) space
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m , vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}


// O(m * n) time, O(m) space
int uniquePaths2(int m, int n) {
    vector<int> prev(n, 1), cur(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            cur[j] = prev[j] + cur[j - 1];
        }
        std::swap(prev, cur);
    }
    return prev[n - 1];
}

// use only 1 row
int uniquePaths3(int m, int n) {
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cur[j] += cur[j - 1];
        }
    }
    return cur[n - 1];
}

// use math,
int uniquePaths5(int m, int n) {
    int N = n + m - 2;// how much steps we need to do
    int k = m - 1; // number of steps that need to go down
    double res = 1;
    // here we calculate the total possible path number
    // Combination(N, k) = n! / (k!(n - k)!)
    // reduce the numerator and denominator and get
    // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
    for (int i = 1; i <= k; i++)
        res = res * (N - k + i) / i;
    return (int)res;
}