//
// Created by brayden on 1/6/21.
//

#include <cstdlib>
#include <cstdio>
#include "random_bit.h"


int random_set_bit(int data) {
    if (data == 0) return 0;
    int newData = data;
    do {
        int m = rand();
        newData &= ~(1 << (rand() % 32));
    } while (newData == data);
    return newData;
}