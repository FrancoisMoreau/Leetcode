//
// Created by brayden on 2020-08-08.
//

#include "problem247.h"

using std::vector;
using std::string;

// My solution, 100%. but too long
string repeat(string cur_path, int n) {
    while (n--) {
        if (cur_path[n] == '6' || cur_path[n] == '9')
            cur_path += char('0' + 54 / (cur_path[n] - '0'));
        else
            cur_path += cur_path[n];

    }
    return cur_path;
}

void subconstruct(vector<string> &res, const vector<char> &elements, string &path, int n, int cur_len, bool isodd) {
    if (cur_len == n) {
        if (isodd) {
            res.push_back(repeat(path + '0', n));
            res.push_back(repeat(path + '1', n));
            res.push_back(repeat(path + '8', n));
        } else {
            res.push_back(repeat(path, n));
        }
        return ;
    }
    for (char c : elements) {
        if (cur_len == 0 && c == '0') continue;
        path.push_back(c);
        subconstruct(res, elements, path, n, cur_len + 1, isodd);
        path.pop_back();
    }
}

vector<string> findStrobogrammatic(int n) {
    vector<char> elements{'0', '1', '6', '8', '9'};
    vector<string> res;
    string path;
    subconstruct(res, elements, path, n / 2, 0, n % 2);
    return res;
}

vector<string> find(int m, int n) {
    if (m == 0) return {""};
    if (m == 1) return {"0", "1", "8"};
    vector<string> t = find(m - 1, n), res;
    for (auto &a : t) {
        if (m != n) res.push_back("0" + a + "0");
        res.push_back("1" + a + "1");
        res.push_back("6" + a + "9");
        res.push_back("9" + a + "6");
        res.push_back("8" + a + "8");
    }
    return res;
}

vector<string> findStrobogrammatic2(int n) {
    return find(n, n);
}

// iteration
vector<string> findStrobogrammatic3(int n) {
    vector<string> one{"0", "1", "8"}, two{""}, res = two;
    if (n % 2 == 1) res = one;
    for (int i = (n % 2) + 2; i <= n; i += 2) {
        vector<string> t;
        for (auto a : res) {
            if (i != n) t.push_back("0" + a + "0");
            t.push_back("1" + a + "1");
            t.push_back("6" + a + "9");
            t.push_back("8" + a + "8");
            t.push_back("9" + a + "6");
        }
        res = t;
    }
    return res;
}