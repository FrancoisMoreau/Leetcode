//
// Created by brayden on 2020-08-10.
//

#ifndef INC_301_350_PROBLEM304_H
#define INC_301_350_PROBLEM304_H

#include <vector>

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>>& matrix);

    int sumRegion(int row1, int col1, int row2, int col2);

private:
    std::vector<std::vector<int>> accu;

};


#endif //INC_301_350_PROBLEM304_H
