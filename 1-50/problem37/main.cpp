#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;

bool insert_check_map(vector<vector<std::unordered_set<int>>> &check_map, int row, int col, int val) {
    if (check_map[0][row].find(val) != check_map[0][row].end()
    || check_map[1][col].find(val) != check_map[1][col].end()
    || check_map[2][row / 3 * 3 + col / 3].find(val) != check_map[2][row / 3 * 3 + col / 3].end())
        return false;
    check_map[0][row].insert(val);
    check_map[1][col].insert(val);
    check_map[2][row / 3 * 3 + col / 3].insert(val);
    return true;

}

void fill_sudoku(vector<vector<char>> &res, vector<vector<char>> &path,
        vector<vector<std::unordered_set<int>>> &check_map, int idx) {
    if (!res.empty()) return;
    if (idx == 81) {
        res = path;
        return;
    }
    int row = idx / 9, col = idx % 9;
    if (path[row][col] == '.') {
        int val = 1;
        for (;  val < 10; ++val) {
            if (insert_check_map(check_map, row, col, val)) {
                path[row][col] = '0' + val;
                fill_sudoku(res, path, check_map, idx + 1);
                path[row][col] = '.';
                check_map[0][row].erase(val);
                check_map[1][col].erase(val);
                check_map[2][row / 3 * 3 + col / 3].erase(val);
            }
        }
        if (val == 10) return ;
    } else {
        fill_sudoku(res, path, check_map, idx + 1);
    }
}



void solveSudoku(vector<vector<char>>& board) {
    std::vector<std::unordered_set<int>> rows(9);
    std::vector<std::unordered_set<int>> cols(9);
    std::vector<std::unordered_set<int>> boxes(9);
    std::vector<vector<std::unordered_set<int>>> check_map{rows, cols, boxes};
    std::vector<vector<char>> res;
    for (int row = 0; row < 9; ++ row) {
        for (int col = 0; col < 9; ++ col) {
            if (board[row][col] != '.') {
                insert_check_map(check_map, row, col, board[row][col] - '0');
            }
        }
    }
    fill_sudoku(res, board, check_map, 0);
    board = res;
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