//
// Created by brayden on 2020-08-18.
//

#include "problem921.h"

using std::string;

int minAddToMakeValid(string S) {
    int count = 0, left = 0;
    for (char c : S) {
        if (c == '(') {
            left++;
        } else if (c == ')') {
            if (!left) ++count;
            else {
                --left;
            }
        }
    }
    count += left;
    return count;
}