//
// Created by brayden on 2020-05-25.
//

#include "problem415.h"

using std::string;

string addStrings2(string num1, string num2) {
    int carry = 0;
    int bit = 0, lhs = 0, rhs = 0;
    string res;
    while (bit < num1.size() || bit < num2.size()) {
        lhs = bit < num1.size() ? *(num1.cend() - 1 - bit) - '0' : 0;
        rhs = bit < num2.size() ? *(num2.cend() - 1 - bit) - '0' : 0;
        res = char('0' + (lhs + rhs + carry) % 10 ) + res;
        carry = (lhs + rhs + carry) / 10;
        ++bit;
    }
    if (carry) res += "1" + res;
    return res;
}

// 30%, 100%
string addString(string num1, string num2) {
    int sum = 0, i = num1.size() - 1, j = num2.size() - 1;
    string str;
    while (i >= 0 || j >= 0 || sum > 0) {
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        str.insert(0, 1 , (sum % 10) + '0');
        sum /= 10;
    }
    return str;
}