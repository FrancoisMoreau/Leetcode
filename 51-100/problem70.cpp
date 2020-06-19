//
// Created by brayden on 2020-06-16.
//

#include "problem70.h"


int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    n -= 2;
    while (n--) {
        int sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}