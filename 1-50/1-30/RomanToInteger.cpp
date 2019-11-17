int romanToInt(std::string s) {
    std::map<char, int> romantbl;
    romantbl.insert({'M', 1000});
    romantbl.insert({'C', 100});
    romantbl.insert({'X', 10});
    romantbl.insert({'I', 1});
    romantbl.insert({'D', 500});
    romantbl.insert({'L', 50});
    romantbl.insert({'V', 5});
    auto prev = s.cbegin();
    int res = 0;
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        res += romantbl[*it];
        if (romantbl[*it] > romantbl[*prev])
            res -= 2 * romantbl[*prev];
        prev = it;
    }
    return res;
}
