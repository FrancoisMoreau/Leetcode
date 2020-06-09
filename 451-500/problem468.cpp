//
// Created by brayden on 2020-06-08.
//

#include "problem468.h"

#include <sstream>
using std::string;

bool check_IPv4(const string &IP) {
    std::stringstream ss(IP);
    string tmp;
    if (std::count(IP.begin(), IP.end(), '.') != 3) return false;
    int cnt = 0;
    while (getline(ss, tmp, '.')) {
        if (tmp.size() > 3 || tmp.empty()) return false;
        if (tmp[0] == '0' && tmp.size() > 1) return false;
        for (auto &i : tmp) {
            if (i < '0' || i > '9') return false;
        }
        if (std::stoi(tmp) > 255) return false;
        cnt++;
    }
    return cnt == 4;
}

bool check_IPv6(string IP) {
    if (std::count(IP.begin(), IP.end(), ':') != 7) return false;
    int pos = 0;
    IP += ':';
    while (IP.find(':', pos) != string::npos) {
        int cur = IP.find(':', pos);
        if (cur - pos > 4 || cur == pos) return false;
        for (auto &i : IP.substr(pos, cur - pos)) {
            if (!((i <= 'F' && i >= 'A') || (i <= 'f' && i >= 'a') || (i <= '9' && i >= '0')))
                return false;
        }
        pos = cur + 1;
    }
    return true;
}

string validIPAddress(string IP) {
    if (IP.find('.') != string::npos  && check_IPv4(IP)) {
        return "IPv4";
    } else if (IP.find(':') != string::npos && check_IPv6(IP)) {
        return "IPv6";
    }
    return "Neither";
}