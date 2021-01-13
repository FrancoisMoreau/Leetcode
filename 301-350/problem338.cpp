//
// Created by brayden on 1/5/21.
//

#include "problem338.h"

using std::vector;

// My naive solution
int subcount(int num) {
    int count = 0;
    while (num) {
        if (num & 0x01) count++;
        num >>= 1;
    }
    return count;
}

vector<int> countBits(int num) {
    vector<int> res;
    for (int i = 0; i <= num; i++) {
        res.push_back(subcount(i));
    }
    return res;
}


// we can use dynamic programming here!
vector<int> countBits2(int num) {
    vector<int> res(num + 1, 0);
    for (int i = 0; i <= num; i++) {
        res[i] = res[i>>1] + (i & 1);
    }
    return res;
}

// count set bits in an integer
int num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
int count_bits(unsigned int num) {
    int last = 0;
    if (num == 0) return num_to_bits[0];
    last = num & 0xf;
    return num_to_bits[last] + count_bits(num >> 4);
}