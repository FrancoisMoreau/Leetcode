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
