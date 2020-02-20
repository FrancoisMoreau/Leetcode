//
// Created by brayden on 2020-02-20.
//

#include "problem118.h"

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> Triangle;
    for (int i = 0; i < numRows; ++i) {
        vector<int> cur_row(i + 1, 1);
        for (int j = 1; j < i / 2 + 1; ++j) {
            cur_row[j] = Triangle[i - 1][j - 1] + Triangle[i - 1][j];
        }
        std::copy(cur_row.begin(), cur_row.begin() + (i + 1) / 2, cur_row.end() - (i + 1) / 2 );
        std::reverse(cur_row.end() - (i + 1) / 2 , cur_row.end());
        Triangle.push_back(cur_row);
    }
    return Triangle;
}