//
// Created by brayden on 2020-06-16.
//

#include "problem509.h"

// interation
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    int a[2] = {0, 1};
    bool cond = true;
    while (--N) {
        a[cond] = a[cond] + a[!cond];
        cond = !cond;
    }
    return a[cond];
}

// recursion
int fib2(int N) {
    if(N == 0)  return 0;
    if(N == 1)  return 1;
    return fib(N-1) + fib(N-2);
}