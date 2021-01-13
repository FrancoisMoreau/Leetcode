//
// Created by brayden on 2020-02-28.
//

#include "problem91.h"
#include <vector>

using std::vector;


// solution after half year, Oct 2020

int numDecodin(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i <= n; i++) {
        int onedig = std::stoi(s.substr(i - 1, 1));
        int twodig = std::stoi(s.substr(i - 2, 2));
        if (onedig >= 1 && onedig <= 9)
            dp[i] += dp[i - 1];
        if (twodig >= 10 && twodig <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
}

// My original thought was wrong
// we should implement dynamic programming here

// wrong code !!!
int numDecodings_wrongcode(string s) {
    if (s[0] == '0') return 0;
    vector<int> max(s.size(), 1);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (s[i - 1] == '0' || s[i - 1] > '2') return 0;
            if (i > 1 && max[i - 1] != max[i - 2]) max[i] = max[i - 2];
            else max[i] = max[i - 1];
        } else if (s[i] < '7') {
            if (s[i - 1] < '3' && s[i - 1] != '0')
                max[i] = max[i - 1] + 1;
            else max[i] = max[i - 1];
        } else {
            if (s[i - 1] < '2' && s[i - 1] != '0')
                max[i] = max[i - 1] + 1;
            else max[i] = max[i - 1];
        }
    }
    return max[s.size() - 1];
}

//Solution
// for '1212':
// 1, 2, 1, (2)
// 12, 1, (2)
// 1, 21, (2)
// ----------
// 1, 2, (12)
// 12, (12)
// dp[i] = dp[i - 1] + dp[i - 2]
// Recalled this and realized it in several days
int numDecodings(string s) {
    if (s[0] == '0') return 0;
    vector<int> dp(s.size() + 1, 1);
    for (int j = 2; j <= s.size(); ++j) {
        int i = j - 1;
        if (s[i] == '0') {
            if (s[i - 1] == '0' || s[i - 1] > '2') return 0;
            else dp[j] = dp[j - 2];
        } else if (s[i] > '6') {
            if (s[i - 1] >= '2' || s[i - 1] == '0')
                dp[j] = dp[j - 1];
            else dp[j] = dp[j - 1] + dp[j - 2];
        } else {
            if (s[i - 1] == '0' || s[i - 1] > '2') dp[j] = dp[j - 1];
            else dp[j] = dp[j - 2] + dp[j - 1];
        }
    }
    return dp.back();
}

//don't need O(n) space in fact
int numDecodings2(string s) {
    if (s.empty() || s[0] == '0') return 0;

    int r1 = 1, r2 = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') r1 = 0;
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            r1 = r2 + r1;
            r2 = r1 - r2;

        } else {
            r2 = r1;
        }
    }
    return r1;

}