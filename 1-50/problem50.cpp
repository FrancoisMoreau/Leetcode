//
// Created by brayden on 2020-05-23.
//

#include <cstdlib>
#include "problem50.h"

// I don't know how did I think this solution out 6 month ago
double myPow2(double x, int n) {
    unsigned absn = abs(long(n));
    double res = 1, path = x;
    while (absn) {
        if (absn & 0x01) res *= path;
        path *= path;
        absn >>= 1;
    }
    if (n >= 0) return res;
    else return 1/ res;
}

// Soulmachine solution
double power(double x, int n) {
    if (n == 0) return 1;
    double v = power(x, n / 2);
    if (n % 2 == 0) return v * v;
    else return v * v * x;
}

double myPow(double x, int n) {
    if (n < 0) return 1.0 / power(x, n);
    else return power(x, n);
}