#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;

inline void insert_check_map(vector<vector<int>> &check_map, int row, int col, int val) {
    check_map[0][row] = check_map[0][row] ^ (1 << val);
    check_map[1][col] = check_map[1][col] ^ (1 << val);
    check_map[2][row / 3 * 3 + col / 3] = check_map[2][row / 3 * 3 + col / 3] ^ (1 << val);
}

void fill_sudoku(vector<vector<char>> &path,
        vector<vector<int>> &check_map, int idx, bool &filled) {
    if (idx == 81) {
        filled = true;
        return;
    }
    int row = idx / 9, col = idx % 9, box_idx = row / 3 * 3 + col / 3;
    if (path[row][col] == '.') {
        for (int val = 1;  val < 10; ++val) {
            if (((check_map[0][row] >> val) & 1) || ((check_map[1][col] >> val) & 1)
            || ((check_map[2][box_idx] >> val) & 1))
                continue;
            else {
                insert_check_map(check_map, row, col, val);
                path[row][col] = '0' + val;
                fill_sudoku(path, check_map, idx + 1, filled);
                if (filled) return;
                path[row][col] = '.';
                insert_check_map(check_map, row, col, val);
            }
        }
    } else {
        fill_sudoku(path, check_map, idx + 1, filled);
    }
}


void solveSudoku(vector<vector<char>>& board) {
    vector<int> rows(9), cols(9), boxes(9);
    vector<vector<int>> check_map{rows, cols, boxes};

    for (int row = 0; row < 9; ++ row) {
        for (int col = 0; col < 9; ++ col) {
            if (board[row][col] != '.') {
                insert_check_map(check_map, row, col, board[row][col] - '0');
            }
        }
    }
    bool filled = false;
    fill_sudoku(board, check_map, 0, filled);
}


int main() {
    vector<vector<char>> input = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };

    solveSudoku(input);

    for (auto &i : input) {
        for (auto &j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}