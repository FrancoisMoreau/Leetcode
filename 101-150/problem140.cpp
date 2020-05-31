//
// Created by brayden on 2020-05-30.
//

#include "problem140.h"

#include <unordered_set>
#include <unordered_map>
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::string;

// use dp
// if I use vector<vector<string>>, TLE error
vector<string> wordBreakII1(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dict.find(s.substr(j, i - j)) != dict.end() && !dp[j].empty()) {
                for (auto &k : dp[j]) {
                    dp[i].push_back(k + " " + s.substr(j, i - j));
                }
            }
        }
    }
    for (auto &i : dp[n]) {
        i = i.substr(1);
    }
    return dp[n];
}

// my another try
vector<string> wordBreakII2(string s, vector<string>& wordDict) {
    unordered_map<string, int> dict;
    for (int i = 0; i < wordDict.size(); ++i) {
        dict[wordDict[i]] = i;
    }

    int n = s.size();
    vector<vector<vector<int>>> dp(n + 1);
    dp[0] = {{0}};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dict.find(s.substr(j, i - j)) != dict.end() && !dp[j].empty()) {
                for (auto &k : dp[j]) {
                    dp[i].push_back(k);
                    dp[i].back().push_back(i);
                }
            }
        }
    }
    vector<string> res;
    for (auto &i : dp[n]) {
        string tmp;
        int prev = 0;
        for (int j = 1; j < i.size(); ++j) {
            tmp += s.substr(prev, i[j] - prev) + " ";
            prev = i[j];
        }
        tmp.pop_back();
        res.push_back(tmp);
    }
    return res;
}

// DFS
// fast
vector<string> combine(string word, vector<string> prev) {
    for (int i = 0; i < prev.size(); ++i) {
        prev[i] += " " + word;
    }
    return prev;
}

vector<string> dfs(string s, unordered_set<string> &dict, unordered_map<string, vector<string>> &mp) {
    if (mp.count(s)) return mp[s];
    vector<string> res;
    if (dict.count(s)) res.push_back(s);
    for (int i = 1; i < s.size(); ++i) {
        string word = s.substr(i);
        if (dict.count(word)) {
            string rem = s.substr(0, i);
            vector<string> prev = combine(word, dfs(rem, dict, mp));
            res.insert(res.end(),prev.begin(), prev.end());
        }
    }
    mp[s] = res;
    return res;
}

vector<string> wordBreakII(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> mp;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return dfs(s, dict, mp);

}