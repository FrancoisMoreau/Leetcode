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

//自己写的很多问题，　情况太多了。　
int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;
        while (str[i] == ' ' && i < n) i++;
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        for (; i < n; i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT32_MAX / 10 ||
                (num == INT32_MAX/10 &&(str[i] - '0') > INT32_MAX %10)) {
                return sign == -1 ? INT32_MIN : INT32_MAX;
            }
            printf("num: %d\n", num);
            num = num * 10 + (str[i] - '0');
        }
        return num * sign;
}
