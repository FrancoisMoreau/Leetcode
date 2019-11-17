int reverse_integer(int x) {
    int m = x;
    int res = 0;
    while (m) {
        res = res * 10 + m %10;
        m = m /10;
    }
    return res;
}
// 这里是自己第一次写的版本，　很明显没有考虑到溢出的情况


int reverse(int x) {
    long long r = 0;
    long long t = x;
    t = t > 0 ? t : -t;
    for (; t; t = t/10)
        r = r * 10 + r % 10;
    bool sign = x > 0 ? false : true;
    if (r > 2147483647 || (sign && r > 2147483648)) {
        return 0;
    } else {
        if (sign)
            return -r;
        else
            return r;
    }
}
