//
// Created by brayden on 2020-05-17.
//

#include "problem987.h"

#include <map>
#include <set>
using std::set;
using std::vector;
using std::map;
using std::pair;

void preorder_traverse(TreeNode *x, map<int, set<pair<int, int>>> &vertical, int pos, int height) {
    if (!x) return;
    vertical[pos].emplace(height, x->val);
    preorder_traverse(x->left, vertical, pos - 1, height + 1);
    preorder_traverse(x->right, vertical, pos + 1, height + 1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, set<pair<int, int>>> vertical;
    preorder_traverse(root, vertical, 0, 0);
    vector<vector<int>> res;
    res.reserve(vertical.size());
    for (auto &i : vertical) {
        vector<int> tmp;
        for (auto &j : i.second)
            tmp.push_back(j.second);
        res.push_back(tmp);
    }
    return res;
}