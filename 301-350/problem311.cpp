//
// Created by brayden on 2020-08-07.
//

#include "problem311.h"

using std::vector;

vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int m = A.size(), n = B[0].size(), k = B.size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < k; ++l) {
                if (A[i][l] == 0 || B[l][j] == 0) continue;
                res[i][j] += A[i][l] * B[l][j];
            }
        }
    }
    return res;
}


vector<vector<int>> multiply2(vector<vector<int>> &A, vector<vector<int>> &B) {
    int m = A.size(), n = B[0].size(), k = B.size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int l = 0; l < k; ++l) {
            if (A[i][l] != 0) {
                for (int j = 0; j < n; ++j) {
                    if (B[l][j] != 0) res[i][j] += A[i][l] * B[l][j];
                }
            }
        }
    }
    return res;
}

