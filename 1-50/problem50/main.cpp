#include <iostream>
#include <vector>

using namespace std;

double myPow(double x, int n) {
    unsigned abs_n = abs(long(n));

    double res = 1.0;
    double path = x;
    while (abs_n) {
        int bit = abs_n & (0x01);
        if (bit) res *= path;
        path *= path;
        abs_n >>= 1;
    }
    if (n >= 0) return res;
    else return 1.0 / res;
}

double power(double x, int n) {
    if (n == 0) return 1;
    double v = power(x, n / 2);
    if (n % 2 == 0) return v * v;
    else return v * v * x;
}

double myPow2(double x, int n) {
    if (n < 0) return 1.0 / power(x, n);
    else return power(x, n);
}

int main() {
    cout << myPow(2.0, 10) << endl;
    cout << myPow(2.1, 3) << endl;
    cout << myPow(2.0, -2) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}