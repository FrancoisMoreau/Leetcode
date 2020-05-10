//
// Created by brayden on 2020-02-28.
//

#include "problem93.h"

using std::to_string;
// Attention on the edge cases!
//dfs
void subcnt(string s, string cur, int num, vector<string> &res) {
    if (s.size() > 12) return;
    if (num == 3) {
        if (s[0] == '0' && s.size() > 1) return;
        if (std::stoi(s) <= 255) {
            res.push_back(cur + s);
        }
        return;
    }
    for (int i = 1; i < 4; ++i) {
        if (s.size() < i + 3 - num) break;
        if (s[0] == '0' && i > 1) break;
        if (s.size() >= i &&  std::stoi(s.substr(0, i)) <= 255)
            subcnt(s.substr(i), cur + s.substr(0, i) + ".", num + 1, res);
    }
}

vector<string> restoreIpAddresses2(string s) {
    vector<string> ret;
    string ans;

    for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
            for (int c=1; c<=3; c++)
                for (int d=1; d<=3; d++)
                    if (a+b+c+d == s.length()) {
                        int A = stoi(s.substr(0, a));
                        int B = stoi(s.substr(a, b));
                        int C = stoi(s.substr(a+b, c));
                        int D = stoi(s.substr(a+b+c, d));
                        if (A<=255 && B<=255 && C<=255 && D<=255)
                            if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                                ret.push_back(ans);
                    }
    return ret;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    subcnt(s, "", 0, res);
    return res;
}