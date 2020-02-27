//
// Created by brayden on 2020-02-26.
//

#include "problem20.h"

#include <stack>

bool isValid(string s) {
    if (s.size() < 1) return true;
    std::stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
            if (s.size() - i < stk.size()) return false;
            continue;
        }
        switch(s[i]) {
            case ')': {
                if (stk.top() == '(') stk.pop();
                else return false;
                break;
            }
            case ']': {
                if (stk.top() == '[') stk.pop();
                else return false;
                break;
            }
            default: {
                if (stk.top() == '{') stk.pop();
                else return false;
                break;
            }
        }
    }
    return stk.empty();
}

// one shorter answer
bool isValid2(string s) {
    std::stack<char> stk;
    for(const auto& c : s){
        switch(c){
            case '{':  stk.push('}'); break;
            case '[':  stk.push(']'); break;
            case '(':  stk.push(')'); break;
            default:
                if(stk.size() == 0 || c != stk.top()) return false;
                else stk.pop();
        }
    }
    return stk.size() == 0;
}