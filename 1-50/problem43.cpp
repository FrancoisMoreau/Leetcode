//
// Created by brayden on 2020-08-15.
//

#include "problem43.h"
#include <vector>

using std::string;
using std::vector;

// 30%, 50%, extremely short!
string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> pos(m + n);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];

            pos[p1] += sum / 10;
            pos[p2] = sum % 10;
        }
    }

    string res;
    for (int val : pos) {
        if (!(res.empty() && val == 0))
            res += char('0' + val);
    }
    return res.empty() ? "0" : res;

}