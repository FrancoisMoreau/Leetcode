//
// Created by brayden on 2020-08-18.
//

#include "problem32.h"
#include <stack>
#include <vector>

using std::vector;
using std::string;
using std::stack;

// using stack, 50%, 70%
int longestValidParentheses(string s) {
    stack<int> op;
    int max_cp = 0, last = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            op.push(i);
        else {
            if (op.empty()) {
                last = i;
            } else {
                op.pop();
                if (op.empty())
                    max_cp = std::max(max_cp, i - last);
                else
                    max_cp = std::max(max_cp, i - op.top());
            }
        }
    }
    return max_cp;
}

// dp, 90%, 23%
int longestValidParentheses2(string s) {
    vector<int> dp(s.size(), 0);
    int leftcount = 0, res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++leftcount;
        } else if (leftcount > 0) {
            dp[i] = dp[i - 1] + 2;
            dp[i] += i - dp[i] >= 0? dp[i - dp[i]] : 0;
            res = std::max(res, dp[i]);
            --leftcount;
        }
    }
    return res;
}

// O(n) time, O(1) space, 90%, 98%
int longestValidParentheses3(string s) {
    int res = 0, left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
        s[i] == '(' ? ++left : ++right;
        if (left == right) res = std::max(res, 2 * right);
        else if (left < right) left = right = 0;
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        s[i] == '(' ? ++left : ++right;
        if (left == right) res = std::max(res, 2 * right);
        else if (right < left) left = right = 0;
    }
    return res;
}