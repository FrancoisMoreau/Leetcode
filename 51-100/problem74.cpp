//
// Created by brayden on 2020-06-07.
//

#include "problem74.h"

using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int lo = 0, hi = rows * cols - 1;
    while (lo <= hi) {
        int mid = lo + (hi -  lo ) / 2;
        if (matrix[mid / cols][mid % cols] == target) return true;
        else if (matrix[mid / cols][mid % cols] > target) hi = mid - 1;
        else lo = mid + 1;
    }
    return false;
}