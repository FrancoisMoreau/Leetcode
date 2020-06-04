//
// Created by brayden on 2020-06-03.
//

#include "problem977.h"

using std::vector;

// use stl, nlogn though. 30% time
vector<int> sortedSquares(vector<int>& A) {
    for (auto &i : A)
        i = i * i;
    std::sort(A.begin(), A.end());
    return A;
}


// one pass, 90%
vector<int> sortedSquare2(vector<int> &A) {
    vector<int> res(A.size());
    int lhs = 0, rhs = A.size() - 1;
    for (int i =  A.size() - 1; i >= 0 ; --i) {
        if (abs(A[lhs]) > abs(A[rhs])) res[i] = A[lhs] * A[lhs++];
        else res[i] = A[rhs] * A[rhs--];
    }
    return res;
}