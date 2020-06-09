//
// Created by brayden on 2020-06-08.
//

#include "problem79.h"

using std::vector;
using std::string;

bool dfs(vector<vector<char>> &board, int row, int col, const string &word, int pos) {
    if (pos == word.size()) return true;
    if (board[row][col] == '#') return false;
    if (board[row][col] == word[pos]) {
        // notice that if current is ok, we should return true
        if (pos == word.size() - 1) return true;
        char tmp = board[row][col];
        board[row][col] = '#';
        if (row  > 0 && dfs(board, row - 1, col, word, pos + 1)) return true;
        if (row + 1 < board.size() && dfs(board, row + 1, col, word, pos + 1)) return true;
        if (col > 0 && dfs(board, row, col - 1, word, pos + 1)) return true;
        if (col + 1 < board[0].size() && dfs(board, row, col + 1, word, pos + 1)) return true;
        board[row][col] = tmp;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.empty()) return false;
    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dfs(board, i, j, word, 0))
                return true;
        }
    }
    return false;
}