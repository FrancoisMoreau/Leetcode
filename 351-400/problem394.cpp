//
// Created by brayden on 2020-06-07.
//

#include "problem394.h"

#include <stack>
#include <sstream>

using std::stack;
using std::string;

// 100%, 40%, while my code is too much
string decodeString2(string s) {
    stack<int> times;
    stack<string> contents;
    int num = 0;
    string str, res;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + c - '0';
        } else if (c == '[') {
            times.push(num);
            num = 0;
            if (!str.empty()) {
                contents.push(str);
                str = "";
            }
        } else if (c == ']') {
            int time = times.top();
            times.pop();
            std::stringstream stream;
            while (time--) {
                stream <<  str;
            }
            str = stream.str();
            if (times.size() > contents.size()) continue;
            if (contents.empty()) {
                res += str;
                str = "";
            } else {
                str = contents.top() + str;
                contents.pop();
            }
        } else {
            if (times.empty()) res += c;
            else str += c;
        }
    }
    return res;
}

// a simpler version using stack
string decodeString3(const string &s, int &i) {
    stack<string> chars;
    stack<int> nums;
    string res;
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (isalpha(c)) {
            res.push_back(c);
        } else if (c == '[') {
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        } else {
            string tmp = res;
            int cur_times = nums.top();
            nums.pop();
            while (--cur_times) res += tmp;
            res = chars.top() + res;
            chars.pop();
        }
    }
    return res;
}

// The most elegant version
// used recursion
string decodeString(const string &s, int &i) {
    string res;
    while (i < s.length() && s[i] != ']') {
        if (!isdigit(s[i]))
            res += s[i++];
        else {
            int n = 0;
            while (i < s.length() && isdigit(s[i]))
                n = n * 10 + (s[i++] - '0');
            i++; // '['
            string t = decodeString(s, i);
            i++; // ']'
            while (n--) {
                res += t;
            }
        }
    }
    return res;
}

string decodeString(string s) {
    int i = 0;
    return decodeString(s, i);
}