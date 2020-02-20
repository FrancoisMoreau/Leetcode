//
// Created by brayden on 2020-02-20.
//

#include "problem119.h"


//only need to preserve previous row!
vector<int> getRow(int rowIndex) {
    vector<int> prev_row, cur_row;

    for (int i = 0; i <= rowIndex; ++i) {
        cur_row = vector<int>(i + 1, 1);
        for (int j = 1; j < i ; ++j) {
            cur_row[j] = prev_row[j - 1] + prev_row[j];
        }
        prev_row = cur_row;
    }
    return cur_row;
}

