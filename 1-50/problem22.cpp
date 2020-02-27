//
// Created by brayden on 2020-02-26.
//

#include "problem22.h"

//dfs, can be more concise
void generate_helper(vector<string> &res, string &path, int left, int right) {
    if (left < 0) return;
    if (!left && !right) {
        res.push_back(path);
        return;
    }
    if (left < right) {
        path += ")";
        generate_helper(res, path, left, right - 1);
        path.pop_back();
    }
    path += "(";
    generate_helper(res, path, left - 1, right);
    path.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string path;
    generate_helper(res, path, n, n);
    return res;
}

// more concise

void addingpar(vector<string> &v, string str, int n, int m){
    if(n==0 && m==0) {
        v.push_back(str);
        return;
    }
    if(m > 0){ addingpar(v, str+")", n, m-1); }
    if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
}
vector<string> generateParenthesis2(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}

