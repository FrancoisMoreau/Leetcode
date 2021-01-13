//
// Created by brayden on 1/6/21.
//

#include "rotate_string.h"

// My naive solution
bool rotateString(std::string A, std::string B) {
    if (A.size() != B.size()) return false;
    if (A == B) return true;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        std::string cur = A.substr(i) + A.substr(0, i);
        if (cur == B) return true;
    }
    return false;
}

// simple one
bool rotateString2(std::string A, std::string B) {
    return A.size() == B.size() && (A + A).find(B) != std::string::npos;
}