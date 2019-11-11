//
// Created by brayden on 2019-11-10.
//

#include "LongestValidParentheses.h"
#include <stack>
#include <vector>

int LongestValidParentheses::longestValidParentheses2(std::string s) {
    std::stack<char> op;
    int couples = 0, max_cp = 0;
    std::vector<int> label(s.size());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (op.empty() || op.top() == ')')
                op.push(s[i]);
            else {
                op.pop();
                label[i] = 1;
                int j = i - 1;
                while (label[j]) j--;
                label[j] = 1;
            }
        } else {
            op.push(s[i]);
        }
    }
    for (auto &j : label) {
        if (j == 0) {
            max_cp = std::max(max_cp, couples);
            couples = 0;
        } else {
            couples++;
        }
    }
    max_cp = std::max(couples, max_cp);
    return max_cp;

}

int LongestValidParentheses::longestValidParentheses(std::string s) {
    std::stack<int> op;
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