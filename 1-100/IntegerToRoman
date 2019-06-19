
std::string intToRoman(int x) {
    std::map<int, std::string> romap;
    romap.insert({1000, "M"});
    romap.insert({100, "C"});
    romap.insert({10, "X"});
    romap.insert({1, "I"});
    romap.insert({500, "D"});
    romap.insert({50, "L"});
    romap.insert({5, "V"});
    std::string roman;
    for (int factor = 1000; factor != 0; factor/=10) {
        if (x/factor == 9)
            roman += (romap[factor] + romap[10 * factor]);
        else if (x/factor >= 5)
            roman += (romap[5 * factor] + std::string(x / factor - 5, *(romap[factor].c_str())));
        else if (x/factor == 4)
            roman += romap[factor] + romap[5 * factor];
        else
            roman += std::string(x/factor, *(romap[factor].c_str()));
        x = x % factor;
    }
    return roman;
}
