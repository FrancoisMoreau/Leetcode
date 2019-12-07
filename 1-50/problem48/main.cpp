#include <iostream>
#include <vector>

using std::vector;

void rotate(vector<vector<int>>& matrix) {
    const int n = matrix.size();

    for (int row = 0; row < n; ++row) {
        for (int col = row + 1; col < n; ++col) {
            std::swap(matrix[row][col], matrix[col][row]);
        }
    }
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n / 2; ++col) {
            std::swap(matrix[row][col], matrix[row][n - 1 - col]);
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}