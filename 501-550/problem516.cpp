//
// Created by brayden on 2020-06-14.
//

#include "problem516.h"
#include <vector>

using std::string;
using std::vector;

// My solution, 15%, 50%
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][n - 1];
}

// O(2^n), brute force, top-bottom
int longestPalindromeSubseq2(int lhs, int rhs, string &s) {
    if (lhs == rhs ) return 1;
    if (lhs > rhs) return 0;
    if (s[lhs] == s[rhs])
        return longestPalindromeSubseq2(lhs + 1, rhs - 1, s);
    else
        return std::max(longestPalindromeSubseq2(lhs + 1, rhs, s), longestPalindromeSubseq2(lhs, rhs - 1, s));
}

int longestPalindromeSubseq2(string s) {
    return longestPalindromeSubseq2(0, s.size() - 1, s);
}

// O(n ^2), top_bottom with memorization
int longestPalindromeSubseq3(int lhs, int rhs, string &s, vector<vector<int>> &mem) {
    if (lhs == rhs ) return 1;
    if (lhs > rhs) return 0;
    if (mem[lhs][rhs]) return mem[lhs][rhs];

    if (s[lhs] == s[rhs])
        return longestPalindromeSubseq3(lhs + 1, rhs - 1, s, mem);
    else
        return std::max(longestPalindromeSubseq3(lhs + 1, rhs, s, mem), longestPalindromeSubseq3(lhs, rhs - 1, s, mem));
}

int longestPalindromeSubseq3(string s) {
    vector<vector<int>> mem(s.size(), std::vector<int>(s.size(), 0));
    return longestPalindromeSubseq3(0, s.size() - 1, s, mem);
}


// My solution, O(n^2), time and space


// O(n^2) times, O(n) space

int longestPalindromeSubseq5(string s) {
    int n = s.size();
    vector<int> v0(n), v1(n,1), v(n), *i_2=&v0, *i_1=&v1, *i_=&v;
    for(int i=2;i<=n;i++) {//length
        for(int j=0;j<n-i+1;j++)//start index
            i_->at(j) = s[j]==s[i+j-1]?2+i_2->at(j+1):std::max(i_1->at(j),i_1->at(j+1));
        swap(i_1,i_2);
        swap(i_1,i_); //rotate i_2, i_1, i_
    }
    return i_1->at(0);
}