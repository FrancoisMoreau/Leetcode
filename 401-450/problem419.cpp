//
// Created by brayden on 2020-06-03.
//

#include "problem419.h"

#include <unordered_set>

using std::unordered_set;
using std::vector;

// My solution, time O(n), space: O(n)
int countBattleships(vector<vector<char>>& board) {
    int rows = board.size(), columns = board[0].size();
    vector<int> id(rows * columns, -1);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (board[i][j] == 'X') {
                id[i * columns + j] = i * columns + j;
                if (i && board[i - 1][j] == 'X')
                    id[i * columns + j] = id[(i - 1) * columns + j];
                if (j && board[i][j - 1] == 'X')
                    id[i * columns + j] = id[i * columns + j - 1];
            }
        }
    }

    unordered_set<int> dict;
    for (int i = 0; i < id.size(); ++i) {
        if (id[i] != -1)
            dict.emplace(id[i]);
    }
    return dict.size();
}

// time: O(n), space: O(1);
int countBattleships2(vector<vector<char>> &board) {
    int rows = board.size(), columns = board[0].size();
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (board[i][j] == 'X') {
                if ((i && board[i - 1][j] == 'X') || (j && board[i][j - 1] == 'X'))
                    continue;
                else
                    ++count;
            }
        }
    }
    return count;
}