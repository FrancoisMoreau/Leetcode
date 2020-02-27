//
// Created by brayden on 2020-02-26.
//

#include "problem5.h"

#include <vector>
using std::vector;

//dynamic programming
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    int max_len = 1, start = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = true;
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
            if (dp[i][j] && (j - i + 1) > max_len) {
                max_len = j - i + 1;
                start = i;
            }
        }
    }
    return s.substr(start, max_len);
}

// another very fast algorithm
// check this tomorrow!!!
//The smartness exactly lies in the operation of skipping duplicate characters.
//Using such operation, we don't need to check whether the palindrome is
// odd or even compared to many brute force solutions.
//More importantly, suppose the length of continuous duplicates bounded by j and k is len,
// the length of palindromes with center(odd or even) locating in such area is less than len.
// Thus, based on this obersavation, we do not need to check every duplicate characters
// for collecting palindromes. That is, the statement i=k+1 is necessary and efficient.
string longestPalindrome2(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;
        while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
        i = k+1;
        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
        int new_len = k - j + 1;
        if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}

//manacher's algorithm