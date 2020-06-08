//
// Created by brayden on 2020-06-07.
//

#include "problem529.h"

using std::vector;

// My solution, used dfs, 86%, 50%
inline bool isvalid(int row, int col, int row_size, int col_size) {
    return (row >= 0 && row < row_size && col >= 0 && col < col_size);
}

void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, int row_size, int col_size) {
    if (!isvalid(row, col, row_size, col_size) || visited[row][col]) return;
    visited[row][col] = true;
    if (board[row][col] == 'M') {
        board[row][col] = 'X';
        return;
    }
    int count = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (isvalid(row + i, col + j, row_size, col_size) && board[row + i][col + j] == 'M') {
                ++count;
            }
        }
    }
    if (!count) {
        board[row][col] = 'B';
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                dfs(board, visited, row + i, col + j, row_size, col_size);
            }
        }
    } else {
        board[row][col] = '0' + count;
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int row = click[0], col = click[1];
    int row_size = board.size(), col_size = board[0].size();
    vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
    dfs(board, visited, row, col, row_size, col_size);
    return board;
}

// can also use bfs
