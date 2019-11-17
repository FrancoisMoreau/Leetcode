#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

std::string countAndSay(int n) {
    vector<string> say(2);
    say[0] = "1";
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        char prev = say[idx][0];
        int prev_idx = 0;
        int j = 1;
        for (; j < say[idx].size(); ++j) {
            if (prev == say[idx][j]) continue;
            say[1 - idx] += (std::to_string(j - prev_idx)) + prev;
            prev = say[idx][j];
            prev_idx = j;
        }
        say[1 - idx] += (std::to_string(j - prev_idx)) + prev;
        say[idx] = "";
        idx = 1 - idx;
    }
    return say[idx];
}

string getNext(const string &s) {
    std::stringstream ss;
    for (auto i = s.begin(); i != s.end(); ) {
//        auto j = std::find_if(i, s.end(), [&i](char val) { return val != *i; });
        auto j = std::find_if(i, s.end(), std::bind(std::not_equal_to<>(), std::placeholders::_1, *i));
        ss << j - i << *i;
        i = j;
    }
    return ss.str();
}

string count_and_say2(int n) {
    string s("1");
    while (--n)
        s = getNext(s);

    return s;
}

int main() {
    std::cout << countAndSay(4)  << std::endl;
    std::cout << count_and_say2(4) << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}