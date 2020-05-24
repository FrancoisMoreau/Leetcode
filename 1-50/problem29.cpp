//
// Created by brayden on 2020-05-24.
//

#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include "problem29.h"


// my solution 8 month ago
int divide2(int dividend, int divisor) {
    long abs_divident = abs(long(dividend));
    long abs_divisor = abs(long(divisor));

    long res = 0;
    while (abs_divident >= abs_divisor) {
        long temp_divisor = abs_divisor;
        int key = 1;
        while (abs_divident >= temp_divisor) {
            temp_divisor = abs_divisor << key;
            key += 1;
        }
        key = key - 2;
        res += (long(1) << key);
        abs_divident -= temp_divisor >> 1;

    }
    res = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? res : -res;
    res = res > INT32_MAX ? INT32_MAX : res;
    return res;
}

int divide(int dividend, int divisor) {
    long a = abs(long(dividend)), b = abs(long(divisor));
    long res = 0;
    while (a >= b) {
        long c = b;
        for (int i = 0; a >= c; ++i, c <<= 1) {
            a -= c;
            res += 1 << i;
        }
    }

    res =  ((dividend ^ divisor) >> 31 ) ? (-res) : (res);
    return res > INT32_MAX ? INT32_MAX : res;
}