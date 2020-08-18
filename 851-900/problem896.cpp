//
// Created by brayden on 2020-08-16.
//

#include "problem896.h"

using std::vector;

// 95%, 50%
bool isMonotonic(vector<int>& A) {
    bool increase = false, decrease = false;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) {
            if (decrease) return false;
            increase = true;
        } else if (A[i] < A[i - 1]) {
            if (increase) return false;
            decrease = true;
        }
    }
    return true;
}

// can be even more simple
bool isMonotonic2(vector<int> &A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1])
            dec = false;
        if (A[i] < A[i - 1])
            inc = false;
    }
    return inc || dec;
}