//
// Created by brayden on 2020-05-28.
//

#include "problem71.h"

#include <vector>
#include <sstream>

using std::vector;
using std::string;

// 65%， 100%
string simplifyPath2(string path) {
    vector<string> cur_path;
    int prev = 1, cur = 0;
    while (prev < path.size()) {
        cur = path.find('/', prev);
        if (cur == string::npos) cur = path.size();
        if (path.substr(prev, cur - prev) == "." || cur == prev ) {
            prev = cur + 1;
            continue;
        } else if (path.substr(prev, cur - prev) == "..") {
            if (!cur_path.empty()) cur_path.pop_back();
        } else {
            cur_path.push_back(path.substr(prev, cur - prev));
        }
        prev = cur + 1;
    }
    string res = "/";
    for (auto &i : cur_path) {
        printf("%s, \n", i.c_str());
        res += i + "/";
    }
    if (res.size() > 1) res.pop_back();
    return res;
}

// using C++ getline to act like split
// 92%, 100%
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    std::stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        if (tmp == "" or  tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for (auto &str : stk) res += "/" + str;
    return res.empty() ? "/" : res;
}

// optimization, don't need to check ".." 2 times
//while (getline(ss, tmp, '/')) {
//if (tmp == "" || tmp == ".") continue;
//if (tmp != "..") stk.push_back(tmp);
//else if (!stk.empty()) stk.pop_back();
//}

