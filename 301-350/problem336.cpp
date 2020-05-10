//
// Created by brayden on 2020-03-07.
//

#include "problem336.h"

#include <memory>
#include <unordered_map>

using std::unordered_map;
using std::shared_ptr;
using std::unique_ptr;

struct TrieNode {
    TrieNode *next[26];
    int index = -1;
    vector<int> list;
    TrieNode(){
        memset(next,NULL,sizeof(next));
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (next[i]) delete(next[i]);
        }
    }
};

bool isPalindrome(const string &word, int start, int end) {
    while (start < end) {
        if (word[start] != word[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

bool isPalindrome(const string &word) {
    int start = 0, end = word.size() - 1;
    return isPalindrome(word, start, end);
}

int addword(TrieNode* root, const string &word, int index) {
    for (int i = word.size() - 1; i >= 0; --i) {
        int j = word[i] - 'a';
        if (!(root->next[j])) {
            root->next[j] = new TrieNode;
        }
        if (isPalindrome(word, 0, i))
            root->list.push_back(index);
        root = root->next[j];
    }
    root->index = index;
    root->list.push_back(index);
    return 0;
}

void search(TrieNode* root, vector<string> &words, int index, vector<vector<int>> &res) {
    for (int i = 0; i < words[index].size(); ++i) {
        if (root->index >= 0 && root->index != index && isPalindrome(words[index], i, words[index].size() - 1)) {
            res.push_back({index, root->index});
        }
        root = root->next[words[index][i] - 'a'];
        if (!root) return;
    }
    for (int i : root->list) {
        if (i == index) continue;
        res.push_back({index, i});
    }
}

vector<vector<int>> palindromePairs2(vector<string>& words) {
    vector<vector<int>> res;
    TrieNode *root = new TrieNode;
    for (int i = 0; i < words.size(); ++i) {
        addword(root, words[i], i);
    }
    for (int i = 0; i < words.size(); ++i) {
        search(root, words, i, res);
    }
    delete root;
    return res;
}

vector<vector<int>> palindromePairs(vector<string> &words) {
    unordered_map<string, int> dict;
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
        string key = words[i];
        std::reverse(key.begin(), key.end());
        dict[key] = i;
    }
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            string lhs = words[i].substr(0, j);
            string rhs = words[i].substr(j, words[i].size() - j);

            if (dict.find(lhs) != dict.end() && isPalindrome(rhs) && dict[lhs] != i) {
                res.push_back({i, dict[lhs]});
                if (lhs.empty()) res.push_back({dict[lhs], i});
            }
            if (dict.find(rhs) != dict.end() && isPalindrome(lhs) && dict[rhs] != i) {
                res.push_back({dict[rhs], i});
            }
        }
    }
    return res;
}

