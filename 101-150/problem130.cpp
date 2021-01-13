//
// Created by brayden on 2020-10-25.
//

#include "problem130.h"

using std::vector;


// My solution, 73%,  6%
bool check(vector<vector<char>> &board, int i , int j, vector<vector<bool>> &visited) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ) return true;
    if (visited[i][j] || board[i][j] == 'X') return false;
    visited[i][j] = true;
    bool res = false;
    if (check(board, i - 1, j, visited)) res = true;
    if (check(board, i + 1, j, visited)) res = true;
    if (check(board, i, j - 1, visited)) res = true;
    if (check(board, i, j + 1, visited)) res = true;
    return res;
}

void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' ) return;
    board[i][j] = 'X';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
}

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int rows = board.size(), cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    for (int i =0; i < rows; i++) {
        for (int j =0; j < cols; j++) {
            if (board[i][j] == 'O' && !visited[i][j] && !check(board, i, j, visited)) {
                dfs(board, i, j);
            }
        }
    }
}

// another thought