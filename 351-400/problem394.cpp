//
// Created by brayden on 2020-06-07.
//

#include "problem394.h"

#include <stack>
#include <sstream>

using std::stack;
using std::string;

string decodeString(string s) {
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