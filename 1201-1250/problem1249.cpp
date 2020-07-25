//
// Created by brayden on 2020-07-24.
//

#include "problem1249.h"

#include <stack>

using std::stack;
using std::string;

// inspired by problem 301 optimized dfs, find the number of '(' first
// 64%, 75%
string minRemoveToMakeValid2(string s) {
    int lhs = 0, rhs = 0;
    for (char c : s) {
        if (c == '(') ++lhs;
        else if (c == ')') {
            if (lhs > rhs)
                ++rhs;
        }
    }
    lhs = rhs = std::min(lhs, rhs);
    string res;
    for (char c : s) {
        if (c == '(' && lhs > 0) {
            res += c;
            --lhs;
        }
        if (c == ')' && lhs < rhs) {
            res += c;
            --rhs;
        }
        if (c != '(' && c != ')')
            res += c;
    }
    return res;
}

// dfs, 16%, 5%
string dfs(int idx, string s, char left, char right) {
    int count = 0;
    for (int i = idx; i < s.size(); ++i) {
        if (s[i] == left)
            ++count;
        else if (s[i] == right) {
            if (count > 0) {
                --count;
                continue;
            }
            return dfs(i, s.substr(0, i) + s.substr(i + 1), left, right);
        }
    }
    std::reverse(s.begin(), s.end());
    if (right == ')') {
        return dfs(0, s, ')', '(');
    } else {
        return s;
    }
}

string minRemoveToMakeValid(string s) {
    string res = dfs( 0, s, '(', ')');
    return res;
}

// using stack, 36%, 93%
string minRemoveToMakeValid3(string s)  {
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            stk.push(i);
        else if (s[i] == ')') {
            if (stk.empty())
                s[i] = '*';
            else
                stk.pop();
        }
    }
    while (!stk.empty()) {
        s[stk.top()] = '*';
        stk.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}
