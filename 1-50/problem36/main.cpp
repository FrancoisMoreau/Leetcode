#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;

bool isValidSudoku2(vector<vector<char>>& board) {
    for (auto &i : board) {
        std::unordered_set<char> horizontal_set;
        for (auto j : i) {
            if (j != '.') {
                auto ret = horizontal_set.insert(j);
                if (!ret.second) return false;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<char> vertical_set;
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] != '.') {
                auto ret = vertical_set.insert(board[j][i]);
                if (!ret.second) return false;
            }
        }
    }

    for (int i = 0; i < 7; i += 3) {
        for (int j = 0; j < 7; j += 3) {
            std::unordered_set<char> sub_box;
            for (int l = 0; l < 3; ++l) {
                for (int k = 0; k < 3; ++k) {
                    if (board[i+l][j+k] != '.') {
                        auto ret = sub_box.insert(board[i + l][j + k]);
                        if (!ret.second) return false;
                    }
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    std::vector<std::unordered_set<int>> rows(9);
    std::vector<std::unordered_set<int>> columns(9);
    std::vector<std::unordered_set<int>> boxes(9);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                auto ret_row = rows[i].insert(board[i][j]);
                auto ret_col = columns[j].insert(board[i][j]);
                auto ret_box = boxes[i / 3 * 3 + j / 3].insert(board[i][j]);
                if (!ret_row.second || !ret_col.second || !ret_box.second) return false;
            }
        }
    }
    return true;
}

inline int sudokuer(int n, int val) {
    return ((val >> n) & 1) == 1 ? -1 : val ^ (1 << n);
}

bool isValidSudoku3(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        int hori = 0, vert = 0, box = 0;
        for (int j = 0; j < 9; ++j) {
                auto ret_row = (board[i][j]) - 48;
                auto ret_col = (board[j][i]) - 48;
                auto ret_box = board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - 48;
                if (ret_row > 0) hori = sudokuer(ret_row, hori);
                if (ret_col > 0) vert = sudokuer(ret_col, vert);
                if (ret_box > 0) box = sudokuer(ret_box, box);
                if (hori == -1 || vert == -1 || ret_box == -1)
                    return false;
        }
    }
    return true;
}

int main() {
    vector<vector<string>> input =
            {{"5","3",".",".","7",".",".",".","."},
    {"6",".",".","1","9","5",".",".","."},
    {".","9","8",".",".",".",".","6","."},
    {"8",".",".",".","6",".",".",".","3"},
    {"4",".",".","8",".","3",".",".","1"},
    {"7",".",".",".","2",".",".",".","6"},
    {".","6",".",".",".",".","2","8","."},
    {".",".",".","4","1","9",".",".","5"},
    {".",".",".",".","8",".",".","7","9"}};

    vector<vector<char>> sudoku;
    for (auto &i : input) {
        vector<char> temp;
        for (auto &j : i) {
            temp.push_back(j[0]);
        }
        sudoku.push_back(temp);
    }

    for (auto &i : sudoku) {
        for (auto &j : i) {
            printf("%c ", j);
        }
        printf("\n");
    }

    std::cout << "Sudoku is Valid: " << isValidSudoku3(sudoku) << "\n\n";

    std::cout << "Hello, World!" << std::endl;
    return 0;
}