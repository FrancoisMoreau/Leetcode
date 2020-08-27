//
// Created by brayden on 2020-08-21.
//

#include "problem647.h"
#include <vector>

using std::vector;
using std::string;

// My solution, 10%, 70%, n^3!!! bad!!
bool ispalin(const string &s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

int countSubstrings(string s) {
    int n = s.size();
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = i; j >= 0; --j) {
            dp[i] += ispalin(s, j, i);
        }
    }
    return dp[n - 1];
}

// n^2 time, 67%, 86%
int extend(const string &s, int lhs, int rhs) {
    int count = 0;
    while (lhs >= 0 && rhs < s.size() && s[lhs] == s[rhs]) {
        --lhs;
        ++rhs;
        ++count;
    }
    return count;
}

int countSubstrings2(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        count += extend(s, i, i);
        count += extend(s, i, i + 1);
    }
    return count;
}