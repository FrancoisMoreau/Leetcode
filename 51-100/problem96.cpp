//
// Created by brayden on 2020-05-12.
//

#include "problem96.h"

#include <vector>

using std::vector;
int numTrees(int n) {
    vector<int> g(n + 1, 0);
    g[0] = g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            g[i] += g[j] * g[i - 1 - j];
        }
    }
    return g.back();
}