int string_to_integer(std::string str) {
    auto first = str.find_first_of("+-0123456789");
    if (first) {
        if (str.substr(0, first).find_first_not_of(" ") != std::string::npos)
            return 0;
    }
    long long res = std::stoll(str.substr(first));
    if (res < INT32_MIN)
        return INT32_MIN;
    else if (res > INT32_MAX)
        return  INT32_MAX;
    else
        return res;
}
有很多ｂｕｇ，　待update
