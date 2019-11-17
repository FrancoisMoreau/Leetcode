std::string convert_string(std::string s, int numRows) {
    auto len = s.size();
    std::string res;
    int stride = 2 * numRows -2;
    for (int i = 0; i < len; i += stride) {
        res += s[i];
    }
    for (int i = 1; i < numRows -1; ++i) {
        int idx = i;
        int inner_stride[2] = {stride - 2 * i, 2 * i};
        int key = 0;
        while (idx < len) {
            res += s[idx];
            idx += inner_stride[key];
            key = 1 - key;
        }
    }
    for (int i = numRows - 1; i < len; i += stride)
        res += s[i];
    return res;
}
// what I wrote before
string ZigZagConversion(std::string s, int numRows) {
    int len = s.size();
    string res;
    int i, j,rem_par;
    if (numRows <= 1 || s.length() == 0)
        return s;
    for ( i = 0; i <  numRows; ++ i) {
        for ( j = i; j < len; j = j + 2 * (numRows -1)) {
            res += s[j];
            rem_par = j + 2 *(numRows - i -1);
            if (i != 0 && i != (numRows -1)) {
                if (rem_par >= len)
                    continue;
                res += s[rem_par];
            }
        }
    }
    return res;
}
