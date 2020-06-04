//
// Created by brayden on 2020-06-03.
//

#include "problem227.h"
#include <stack>
#include <sstream>
#include <vector>
#include <numeric>

using std::stack;
using std::string;

// I didn't solve this problem

// Although last time path problem inspired me of using sstream, I only tried getline(ss, tmp, ' ') here, sadly
// O(n) time, O(1) space. 80%, 100%
int calculate(string s) {
    std::stringstream ss("+" + s);
    char op;
    int n, last, ans = 0;
    while (ss >> op >> n) {
        if (op == '+' || op == '-') {
            n = op == '+' ? n : -n;
            ans +=  n;
        } else {
            n = op == '*' ? last * n : last / n;
            ans = ans - last + n;
        }
        last = n;
    }
    return ans;
}

// more straightforward thought
int calculate2(string s) {
    std::istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

//using stack
int calculate4(string s) {
    if (s.empty()) return 0;
    s.push_back('+');
    int num = 0;
    char sign = '+';
    std::vector<int> nums;
    for (char& c: s) {
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') num = 10*num + (c-'0');
        else {
            if (sign == '+') nums.push_back(num);
            else if (sign == '-') nums.push_back(-num);
            else if (sign == '*') nums.back() *= num;
            else nums.back() /= num;
            sign = c;
            num = 0;
        }
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}