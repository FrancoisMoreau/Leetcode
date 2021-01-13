//
// Created by brayden on 1/7/21.
//

#include "word_search.h"

using std::vector;
using std::string;

// word search
bool dfs(vector<vector<char>> &board, const string &word, int row, int col, int pos) {
    if (pos == word.size()) return true;
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#' || board[row][col] != word[pos]) return false;
    char tmp = board[row][col];
    board[row][col] = '#';
    if (dfs(board, word, row + 1, col, pos + 1)) return true;
    if (dfs(board, word, row - 1, col, pos + 1)) return true;
    if (dfs(board, word, row, col + 1, pos + 1)) return true;
    if (dfs(board, word, row, col - 1, pos + 1)) return true;
    board[row][col] = tmp;
    return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    if (board.empty()) return false;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

// word search II
struct TrieNode {
    TrieNode *next[26];
    bool is_word = false;
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
    ~TrieNode() {
        for (auto &i : next)
            delete i;
    }
};

void add_word(TrieNode *node, string &cur) {
    for (char c : cur) {
        if (!node->next[c - 'a'])
            node->next[c - 'a'] = new TrieNode();
        node = node->next[c - 'a'];
    }
    node->is_word = true;
}

void dfs22(vector<vector<char>> &board, TrieNode *node, int row, int col, string cur, vector<string> &res) {
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#') return ;
    char cur_c = board[row][col];
    if (node->next[cur_c - 'a'] == nullptr) return ;
    node = node->next[cur_c - 'a'];
    cur += cur_c;
    if (node->is_word) {
        res.push_back(cur);
        node->is_word = false;
    }
    board[row][col] = '#';
    dfs22(board, node, row + 1, col, cur, res);
    dfs22(board, node, row - 1, col, cur, res);
    dfs22(board, node, row, col + 1, cur, res);
    dfs22(board, node, row, col - 1, cur, res);
    board[row][col] = cur_c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    TrieNode *root = new TrieNode();
    for (auto &word : words) add_word(root, word);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            dfs22(board, root, i, j, "", res);
        }
    }
    return res;
}