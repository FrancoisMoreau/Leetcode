//
// Created by brayden on 2020-08-06.
//

#include "problem65.h"

using std::string;

// test(25, ".1", true);
//
//1. skip the leading whitespaces;
//2. check if the significand is valid. To do so, simply skip the leading sign and count the number of digits and the number of points. A valid significand has no more than one point and at least one digit.
//3. check if the exponent part is valid. We do this if the significand is followed by 'e'. Simply skip the leading sign and count the number of digits. A valid exponent contain at least one digit.
//4. skip the trailing whitespaces. We must reach the ending 0 if the string is a valid number.

bool isNumber(string s) {
    int n = s.size(), i = 0, digits = 0, dots = 0;
    for (; i < n && isspace(s[i]); i++);
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
        isdigit(s[i]) ? digits++ : dots++;
    }
    if (!digits || dots > 1)
        return false;
    if (s[i] == 'e') {
        i++;
        if (s[i] == '+' || s[i] == '-')
            i++;
        digits = 0;
        for (; i < n && isdigit(s[i]); i++)
            digits++;
        if (!digits)
            return false;
    }
    for (;i < n && isspace(s[i]); i++);
    return i == n;
}