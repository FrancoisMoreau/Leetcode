//
// Created by brayden on 2020-06-13.
//

#include "problem102.h"
#include <queue>


using std::vector;

// dfs, recursion
void inorder_dfs(TreeNode *node, vector<vector<int>> &res, int h) {
    if (!node) return;
    if (h >= res.size()) res.push_back({node->val});
    else res[h].push_back(node->val);
    inorder_dfs(node->left, res, h + 1);
    inorder_dfs(node->right, res, h + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    inorder_dfs(root, res, 0);
    return res;
}

// Use a queue
vector<vector<int>> levelOrder2(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> res;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int cnt = q.size();
        res.push_back({});
        for (int i = 0; i < cnt; ++i) {
            TreeNode *node = q.front();
            q.pop();
            res.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}