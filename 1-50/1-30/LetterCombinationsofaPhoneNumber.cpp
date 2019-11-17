
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty())
        return res;
    vector<string> dmap{"", "", "abc", "def", "ghi", "jkl", "mno", "prqs", "tuv", "wxyz"};
    for (int i = 0; i < digits.size(); ++i) {
        int num = digits[i] - '0';
        vector<string> tmp = res.empty()? vector<string>(1, "") : res;
        vector<string> tmp2 = tmp;
        res.clear();
            for (int j = 0; j < dmap[num].size(); ++j) {
                for (auto &k : tmp)
                    k +=  dmap[num][j];
            res.insert(res.end(), tmp.begin(), tmp.end());
            tmp = tmp2;
        }
    }
    return res;
}
