//
// Created by brayden on 2020-05-27.
//

#include "problem139.h"
#include <set>
#include <unordered_set>
#include <queue>

using std::set;
using std::unordered_set;
using std::string;
using std::vector;
using std::queue;

//Time Limit Exceeded
struct TrieNode {
    TrieNode *next[26];
    bool is_word = false;
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i)
            delete(next[i]);
    }
};

TrieNode *buildTrie(vector<string> &wordDict) {
    TrieNode *root = new TrieNode;
    for (auto &i : wordDict) {
        TrieNode *node = root;
        for (auto j : i) {
            if (!node->next[j - 'a'])
                node->next[j - 'a'] = new TrieNode;
            node = node->next[j - 'a'];
        }
        node->is_word = true;
    }
    return root;
}

bool wordBreak2(string s, vector<string>& wordDict) {
    if (wordDict.empty()) return false;
    TrieNode *root = buildTrie(wordDict);
    queue<int> posq;
    posq.push(0);
    int n = s.size();
    while (!posq.empty()) {
        int cur_pos = posq.front();
        posq.pop();
        auto node = root;
        while (node && cur_pos < n) {
            if (node->is_word)
                posq.push(cur_pos);
            node = node->next[s[cur_pos++] - 'a'];
        }
        if (cur_pos == n && node && node->is_word)
            return true;
    }
    return false;
}

// use dp, and map
bool wordBreak(string s, vector<string>& wordDict) {
    std::unordered_set<string> dict;
    for (auto &i : wordDict) {
        dict.emplace(i);
    }
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dict.find(s.substr(j, i - j)) != dict.end() && dp[j])
                dp[i] = true;
        }
    }
    return dp[n];
}

// bfs, the idea is same with what I wanted to do with trie,
// but my trie was to slow because I check only 1 char every time
bool wordBreak3(string s, vector<string> &wordDict) {
    queue<int> bfs;
    std::unordered_set<int> visited;
    std::unordered_set<string> dict(wordDict.begin(), wordDict.end());
    bfs.push(0);
    while (!bfs.empty()) {
        int start = bfs.front();
        bfs.pop();
        if (visited.find(start) == visited.end()) {
            visited.insert(start);
            for (int j = start; j < s.size(); ++j) {
                string word(s, start, j - start + 1);
                if (dict.find(word) != dict.end()) {
                    bfs.push(j + 1);
                    if (j + 1 == s.size())
                        return true;
                }
            }
        }
    }
    return false;
}

// dfs, my solution after 2 month, 08/03/2020
// initially without memoization, got a TLE error
// updated with memoization, 50%, 30%
bool dfs(const string &s, const unordered_set<string> &dict, int pos, unordered_set<int> &unmatchecd_set) {
    if (pos == s.size()) return true;
    if (unmatchecd_set.find(pos) != unmatchecd_set.end()) return false;
    for (int i = pos + 1; i <= s.size(); ++i) {
        string cur_substr = s.substr(pos, i - pos);
        if (dict.find(cur_substr) != dict.end()) {
            if (dfs(s, dict, i, unmatchecd_set))
                return true;
            else
                unmatchecd_set.insert(i);
        }
    }
    unmatchecd_set.insert(pos);
    return false;
}

bool wordBreak5(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_set<int> unmatched_set;
    return dfs(s, dict, 0, unmatched_set);
}

