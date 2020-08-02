//
// Created by brayden on 2020-07-27.
//

#include "problem282.h"
#include <sstream>
#include <numeric>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::string;

// My solution, TLE
int calculate(string s) {
    int num = 0;
    char sign = '+';
    s += '+';
    std::vector<int> nums;
    for (char c : s) {
        if (c >= '0' && c<= '9') num = 10 * num + (c - '0');
        else {
            if (sign == '+') nums.push_back(num);
            else if (sign == '-') nums.push_back(-num);
            else nums.back() *= num;
            sign = c;
            num = 0;
        }
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}

void dfs2(const string &num, int pos, string &cur, unordered_set<string> &res, int target) {
    if (pos == num.size()) {
        res.insert(cur.substr(0, cur.size() - 1));
        return;
    }
    for (int i = pos + 1; i <= num.size(); ++i) {
        if (num[pos] == '0' && i > pos + 1)
            break;
        int cur_size = i - pos;
        cur += num.substr(pos, cur_size);
        cur += "+";
        dfs2(num, i, cur, res, target);
        cur.replace(cur.size() - 1, 1, "*");
        dfs2(num, i, cur, res, target);
        cur.replace(cur.size() - 1, 1, "-");
        dfs2(num, i, cur, res, target);
        cur = cur.substr(0, cur.size() - cur_size - 1);
    }
}

vector<string> addOperators8(string num, int target) {
    string cur;
    unordered_set<string> res;
    dfs2(num, 0, cur, res, target);
    vector<string> ans;
    for (auto it = res.begin(); it != res.end(); ++it) {
        if (calculate(*it) == target) {
            ans.push_back(*it);
        }
    }
    return ans;
}

//
void dfs(vector<string> &res, const string &num, const int target, string cur, int pos, long cum_val, long prev_val) {
    if (pos == num.size()) {
        if (cum_val == target)
            res.push_back(cur);
        return;
    }
    for (int i = pos + 1; i <= num.size(); ++i) {
        if (i == pos + 1 && num[pos] == '0')
            break;
        string t = num.substr(pos, i - pos);
        long now = stol(t);
        if (pos == 0) {
            dfs(res, num, target, t, i, now, now);
            continue;
        }
        dfs(res, num, target, cur + "+" + t, i, cum_val + now, now);
        dfs(res, num, target, cur + "-" + t, i, cum_val - now, -now);
        dfs(res, num, target, cur + "*" + t, i, cum_val - prev_val + prev_val * now, prev_val * now);
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(res, num, target, "", 0, 0, 0);
    return res;
}