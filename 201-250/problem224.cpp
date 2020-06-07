//
// Created by brayden on 2020-06-04.
//

#include "problem224.h"
#include <stack>

using std::stack;
using std::string;

// Again, I didn't solve this problem
int calculate(string s) {
    if (s.empty()) return 0;
    int res = 0, sign = 1, num = 0;
    stack<int> stk;
    stk.push(sign);
    for (auto c : s) {
        if (c >= '0' && c <= '9') num = num * 10 + (c - '0');
        else if (c == '+' || c == '-') {
            res += sign * num;
            sign = stk.top() * (c == '+' ? 1 : -1);
            num = 0;
        } else if (c == '(') {
            stk.push(sign);
        } else if (c == ')') {
            stk.pop();
        }
    }
    res += sign * num;
    return res;
}