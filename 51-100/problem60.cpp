//
// Created by brayden on 2020-10-27.
//

#include "problem60.h"

#include <vector>

using std::string;

// My naive solution, slow
string getPermutation(int n, int k) {
    string raw = "";
    for (int i = 0; i < n; i++)
        raw += (i + 1 + '0');

    while (--k) {
        std::next_permutation(raw.begin(), raw.end());
    }
    return raw;
}


// better solution
string getPermutation2(int n, int k) {
    string res;
    string num = "123456789";
    std::vector<int> f(n, 1);
    for (int i = 1; i < n; ++i) {
        f[i] = f[i - 1] * i;
    }
    --k;
    for (int i = n; i >= 1; --i) {
        int j = k / f[i - 1];
        k %= f[i - 1];
        res += num[j];
        num.erase(j, 1);
    }
    return res;
}