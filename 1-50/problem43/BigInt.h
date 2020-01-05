//
// Created by brayden on 2020-01-05.
//

#ifndef PROBLEM43_BIGINT_H
#define PROBLEM43_BIGINT_H

#include <string>
#include <vector>

class BigInt {
public:
    BigInt(std::string s);

    static BigInt multiply(const BigInt &x, const BigInt &y);
    std::string to_string();

private:
    typedef long long int64_t;
    const static int BIGINT_RADIX = 1000000000;
    const static int RADIX_LEN = 9;
    std::vector<int64_t> elems;
    BigInt(const std::vector<int64_t> arg) : elems(arg) {}
};


#endif //PROBLEM43_BIGINT_H
