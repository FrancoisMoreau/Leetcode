//
// Created by brayden on 2020-05-24.
//

#include "problem212.h"

using std::vector;
using std::string;


// Time Limit Exceeded, Use words to construct tries instead
struct TrieNode {
    TrieNode *next[26];
    bool is_word = false;
    TrieNode(){
        memset(next,NULL,sizeof(next));
    }
    ~TrieNode() {
        for (auto &i : next)
            delete i;
    }
};

void construct(vector<vector<char>> &board, vector<vector<bool>> &visited, TrieNode *node, int x, int y, int hor, int ver) {
    if (x < 0 || y < 0 || x >= hor || y >= ver || visited[y][x]) return;
    visited[y][x] = true;
    if (!node->next[board[y][x] - 'a']) {
        node->next[board[y][x] - 'a'] = new TrieNode();
    }
    node = node->next[board[y][x] - 'a'];
    construct(board, visited, node, x - 1, y, hor, ver);
    construct(board, visited, node, x   + 1, y, hor, ver);
    construct(board, visited, node, x,  y - 1, hor, ver);
    construct(board, visited, node, x, y + 1, hor, ver);
    visited[y][x] = false;
}

bool search(const char *word, TrieNode *node) {
    for (int i = 0; word[i] && node; ++i) {
        node = node->next[word[i] - 'a'];
    }
    return node;
}

vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) {
    TrieNode *root = new TrieNode;
    int hor = board[0].size(), ver = board.size();
    vector<vector<bool>> visited(ver, vector<bool>(hor, false));
    for (int i = 0; i < hor; ++i) {
        for (int j = 0; j < ver; ++j) {
            construct(board, visited, root, i, j, hor, ver);
        }
    }
    vector<string> res;
    for (auto &str : words) {
        if (search(str.c_str(), root))
            res.push_back(str);
    }
    return res;
}

// use words to construct nodes instead, and we can use '#' to erase the use of visited
void addWord(TrieNode *node, string &cur_word) {
    for (char c : cur_word) {
        if (!node->next[c - 'a'])
            node->next[c - 'a'] = new TrieNode;
        node = node->next[c - 'a'];
    }
    node->is_word = true;
}

void dfs(vector<vector<char>> &board, TrieNode *node, int x, int y, string cur, vector<string> &res) {
    if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size() || board[y][x] == '#') return;
    if (node->next[board[y][x] - 'a'] == nullptr) return;
    node = node->next[board[y][x] - 'a'];
    cur += board[y][x];
    if (node->is_word) {
        res.push_back(cur);
        node->is_word = false;
    }
    char c = board[y][x];
    board[y][x] = '#';
    dfs(board, node, x - 1, y, cur, res);
    dfs(board, node, x + 1, y, cur, res);
    dfs(board, node, x, y - 1, cur, res);
    dfs(board, node, x, y + 1, cur, res);
    board[y][x] = c;

}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    TrieNode *root = new TrieNode;
    for (auto &str : words) {
        addWord(root, str);
    }
    vector<string> res;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            dfs(board, root, j, i, "", res);
        }
    }
    return res;
}

// 2 optimizations can be done here:
// 1. add word in every trie nood; 2. dfs if (i >0)