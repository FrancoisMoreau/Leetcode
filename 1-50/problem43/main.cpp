#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "BigInt.h"

using std::map;
using std::vector;
using std::string;

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()



class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() < num2.size()) return multiply(num2, num1);
        int n1 = num1.size(), n2 = num2.size();
        int carry = 0;
        map<int, string> mul_val_map;
        string res{"0"};
        for (int i = 0; i < n2; ++i) {
            int val = num2[n2 - 1 - i] - '0';
            if (mul_val_map.find(val) == mul_val_map.end()) {
                mul_val_map.insert({val, mult_one_bit(num1, val)});
            }
            string cur = mul_val_map[val] + std::string(i, '0');
            res = add_str_num(res, cur);
        }
        return res;
    }
private:
    string add_str_num(string &num1, string &num2) {
        int n1 = num1.size(), n2 = num2.size();
        int total_len = std::max(n1, n2);
        std::vector<int> res(total_len);
        int carry = 0;
        for (int i = 0; i < total_len; ++i) {
            int left = i < n1 ? num1[n1 - 1 - i] - '0' : 0;
            int right = i < n2 ? num2[n2 - 1 - i] - '0' : 0;
            int sum = left + right + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) res.push_back(carry);
        string ans;
        for (auto i = res.crbegin(); i != res.crend(); ++i) {
            ans += std::to_string(*i);
        }
        return ans;
    }

    string mult_one_bit(string &num1, int val) {
        int n1 = num1.size();
        int carry = 0;
        vector<int> res(n1);
        for (int i = 0; i < n1; ++i) {
            int str_val = num1[n1 - 1 - i] - '0';
            int mul_res = str_val * val + carry;
            res[i] = mul_res % 10;
            carry = mul_res / 10;
        }
        if (carry) res.push_back(carry);
        string ans;
        for (auto i = res.crbegin(); i != res.crend(); ++i)
            ans += std::to_string(*i);
        return ans;
    }
};

typedef vector<int> bigint;

bigint make_bigint(const string &num) {
    bigint n;
    std::transform(num.rbegin(), num.rend(), back_inserter(n), [](char c) { return c - '0'; });
    return n;
}

bigint operator*(const bigint &lhs, const bigint &rhs) {
    bigint z(lhs.size() + rhs.size());
    for (size_t i = 0; i < lhs.size(); ++i) {
        for (size_t j = 0; j < rhs.size(); ++j) {
            z[i + j] +=  lhs[i] * rhs[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    }
    return z;
}

string to_string(const bigint &n) {
    string res;
    std::transform(std::find_if(n.rbegin(), prev(n.rend()), [](char c) { return c > '\0'; }),
            n.rend(), back_inserter(res), [](char c) { return c + '0'; });
    return res;
}

string multiply(string num1, string num2) {
    return to_string(make_bigint(num1) * make_bigint(num2));
}


int main() {
    Solution myans;
    TimeVar t1 = timeNow();
    for (int i = 0; i < 1000; ++i)
        myans.multiply("123", "456");
    TimeVar t2 = timeNow();
    std::cout << "my solution costs: " << duration(t2 - t1) << " miliseconds\n";

    t1 = timeNow();
    for (int i = 0; i < 1000; ++i)
        multiply("123", "456");
    t2 = timeNow();
    std::cout << "soulmachine costs: " << duration(t2 - t1) << " miliseconds\n";

    BigInt bgi_x("123");
    BigInt big_y("456");
    std::cout << BigInt::multiply(bgi_x, big_y).to_string() << std::endl;

    return 0;
}