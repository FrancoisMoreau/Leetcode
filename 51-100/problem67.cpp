//
// Created by brayden on 2020-07-26.
//

#include "problem67.h"

using std::string;


string addBinary(string a, string b) {
    int lhs_size = a.size(), rhs_size = b.size();
    int pos = 0, lhs = 0, rhs = 0, carry = 0;
    string res;
    while (pos < std::max(lhs_size, rhs_size)) {
        lhs = pos < lhs_size ? (a[lhs_size - 1 - pos]) - '0' : 0;
        rhs = pos < rhs_size ? (b[rhs_size - 1 - pos]) - '0' : 0;
        res += char('0' + (lhs + rhs + carry) % 2);
        carry = (lhs + rhs + carry) / 2;
        ++pos;
    }
    if (carry) res += '1';
    std::reverse(res.begin(), res.end());

    return res;
}

// simpler one
string addBinary2(string a, string b) {
    string res;
    int lhs = a.size() - 1, rhs = b.size() - 1, carry = 0;
    while (lhs >= 0 || rhs >= 0 || carry) {
        carry += lhs >= 0 ? a[lhs--] - '0' : 0;
        carry += rhs >= 0 ? b[rhs--] - '0' : 0;
        res = char(carry % 2 + '0') + res;
        carry /= 2;
    }
    return res;
}