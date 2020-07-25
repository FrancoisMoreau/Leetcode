//
// Created by brayden on 2020-07-16.
//

#include "problem301.h"
#include <stack>
#include <queue>
#include <unordered_set>

using std::stack;
using std::vector;
using std::string;
using std::unordered_set;

bool isValid(const string &s) {
    int cnt = 0;
    for (auto c : s) {
        if (c == '(') ++cnt;
        if (c == ')') {
            if (cnt > 0) --cnt;
            else return false;
        }
    }
    return !cnt;
}

// naive， 6%， 85%
void dfs(int p, string &cur, const string &s, unordered_set<string> &res) {
    if(p==s.size()) {
        if(isValid(cur)) res.insert(cur);
        return;
    }
    cur+=s[p];
    dfs(p+1,cur,s,res);
    cur.pop_back();
    if(s[p]=='('||s[p]==')') dfs(p+1,cur,s,res);
}

vector<string> removeInvalidParentheses4(string s) {
    string cur;
    unordered_set<string> res;
    dfs(0, cur, s, res);
    int max_size = 0;
    res.insert("");
    for (auto &i : res)
        max_size = std::max(max_size, int(i.size()));
    vector<string> ans;
    for (auto &i : res) {
        if (i.size() == max_size)
            ans.push_back(i);
    }
    return ans;
}

// optimized dfs
void optimized_dfs(string &cur, int idx, int lhs, int rhs, unordered_set<string> &res, const string &s) {
    if (idx == s.size() || lhs < 0 || rhs  < 0 || lhs > rhs) {
        if (!lhs && !rhs && idx == s.size()) res.insert(cur);
        return;
    }
    if (s[idx] != '(' && s[idx] != ')') {
        cur += s[idx];
        optimized_dfs(cur, idx + 1, lhs, rhs, res, s);
    } else {
        optimized_dfs(cur, idx + 1, lhs, rhs, res, s);
        if (s[idx] == '(') {
            cur += '(';
            optimized_dfs(cur, idx + 1, lhs - 1, rhs, res, s);
        } else {
            cur += ')';
            optimized_dfs(cur, idx + 1, lhs, rhs - 1, res, s);
        }
    }
    cur.pop_back();
}

// 50%, 75%
vector<string> removeInvalidParentheses(string s) {
    int lhs = 0, rhs = 0;
    for (char c : s) {
        if (c == '(') ++lhs;
        if (c == ')' && lhs > rhs) ++rhs;
    }
    lhs = rhs = std::min(lhs, rhs);
    string cur;
    unordered_set<string> res;
    optimized_dfs(cur, 0, lhs, rhs, res, s);
    return vector<string>(res.begin(), res.end());
}

// optimal dfs
// 100%， 93%
void subremove(string s, vector<string> &res, int cur, int prev, char lhs, char rhs) {
    int lhs_cnt = 0, rhs_cnt = 0;
    for (int i = cur; i < s.size(); ++i) {
        if (s[i] == lhs) ++lhs_cnt;
        if (s[i] == rhs) ++rhs_cnt;
        if (lhs_cnt >= rhs_cnt) continue;
        for (int j = prev; j <= i; ++j) {
            if (s[j] == rhs && (j == prev || s[j - 1] != rhs))
                subremove(s.substr(0, j) + s.substr(j + 1), res, i, j, lhs, rhs);
        }
        return;
    }
    string reversed(s.rbegin(), s.rend());
    if (rhs == ')') {
        subremove(reversed, res, 0, 0, ')', '(');
    } else {
        res.push_back(reversed);
    }
}

vector<string> removeInvalidParentheses2(string s) {
    vector<string> res;
    subremove(s, res, 0, 0, '(', ')');
    return res;
}

// naive bfs solution


// 30%, 30%
vector<string> removeInvalidParentheses3(string s) {
    std::queue<string> q;
    unordered_set<string> ht;
    q.push(s);
    vector<string> res;
    while (!q.empty()) {
        string ss = q.front();
        q.pop();
        if (ht.count(ss))
            continue;
        ht.insert(ss);
        if (isValid(ss))
            res.push_back(ss);
        else if (res.empty()) {
            for (int i = 0; i < ss.size(); ++i) {
                if (ss[i] == ')' || ss[i] == '(')
                    q.push(ss.substr(0, i) + ss.substr(i + 1));
            }
        }
    }
    return res;
}

