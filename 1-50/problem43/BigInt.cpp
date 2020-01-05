//
// Created by brayden on 2020-01-05.
//

#include "BigInt.h"
#include <sstream>
#include <iomanip>

BigInt::BigInt(std::string s) {
    std::vector<int64_t> result;
    result.reserve(s.size() / RADIX_LEN + 1);

    for (int i = s.size(); i > 0; i -= RADIX_LEN) {
        int start = std::max(i - RADIX_LEN, 0);
        result.push_back(std::stoi(s.substr(start, i - start)));
    }
    elems = result;
}

BigInt BigInt::multiply(const BigInt &x, const BigInt &y) {
    std::vector<int64_t> z(x.elems.size() + y.elems.size());

    for (size_t i = 0; i < x.elems.size(); ++i) {
        for (size_t j = 0; j < y.elems.size(); ++j) {
            z[i + j] += x.elems[i] * y.elems[j];

            if (z[i + j] > BIGINT_RADIX) {
                z[i + j + 1] = z[i + j] / BIGINT_RADIX;
                z[i + j] = z[i + j] % BIGINT_RADIX;
            }
        }
    }
    while (z.back() == 0) z.pop_back();
    return BigInt(z);
}

std::string BigInt::to_string() {
    std::stringstream res;
    bool start = false;
    for (auto ri = elems.rbegin(); ri != elems.rend(); ++ri) {
        if (start) {
            res << std::setw(RADIX_LEN) << std::setfill('0') << *ri;
        } else {
            res << *ri;
            start = true;
        }
    }

    if (!start) return "0";
    else return res.str();
}