//
// Created by brayden on 2020-08-11.
//

#include "problem314.h"
#include <map>
#include <queue>
#include <utility>

using std::map;
using std::vector;

// 67%
void preorder(TreeNode *node, map<int, map<int, vector<int>>> &dict, int x, int y) {
    if (!node) return;
    dict[x][y].push_back(node->val);
    preorder(node->left, dict, x - 1, y + 1);
    preorder(node->right, dict, x + 1, y + 1);
}

std::vector<std::vector<int>> verticalOrder(TreeNode * root) {
    map<int, map<int, vector<int>>> dict;
    preorder(root, dict, 0, 0);
    vector<vector<int>> res;
    for (auto &i : dict) {
        res.push_back({});
        for (auto &j : i.second) {
            res.back().insert(res.back().end(), j.second.begin(), j.second.end());
        }
    }
    return res;
}

// 层序遍历, level traversal
vector<vector<int>> verticalOrder2(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> dict;
    std::queue<std::pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        dict[a.first].push_back(a.second->val);
        if (a.second->left)
            q.push({a.first - 1, a.second->left});
        if (a.second->right)
            q.push({a.first + 1, a.second->right});
    }
    for (auto &i : dict)
        res.push_back(i.second);
    return res;
}
