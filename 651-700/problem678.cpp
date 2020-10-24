//
// Created by brayden on 2020-10-22.
//

#include "problem678.h"
#include <stack>

using std::string;

// an amazing solution
bool checkValidString(string s) {
    int cmin = 0, cmax = 0;
    for (char c : s) {
        if (c == '(') {
            cmin++;
            cmax++;
        } else if (c == ')') {
            cmin--;
            cmax--;
        } else if (c == '*') {
            cmax++;
            cmin--;
        }
        if (cmax < 0) return false;
        cmin = std::max(cmin, 0);
    }
    return cmin == 0;
}

// use 2 stacks
bool checkValidString2(string s) {
    std::stack<int> left, star;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') left.push(i);
        else if (s[i] == '*') star.push(i);
        else {
            if (left.empty() && star.empty()) return false;
            else if (!left.empty()) left.pop();
            else star.pop();
        }
    }
    while (!left.empty() && !star.empty()) {
        if (left.top() > star.top())
            return false;
        left.pop(); star.pop();
    }

    return left.empty();
}