std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string CmnPfx;
    if (strs.empty())
        return  CmnPfx;
    int min_len = INT32_MAX;
    for (auto &i : strs)
        min_len = i.size() < min_len ? i.size() : min_len;
    for (int i = 0; i < min_len; ++i){
        char ref = strs[0][i];
        for (auto &j : strs) {
            if (j[i] != ref)
                return CmnPfx;
        }
        CmnPfx += ref;
    }
    return CmnPfx;
}
