//
// Created by brayden on 2020-06-22.
//

#include "problem113.h"

using std::vector;

// My solution, 64%, 60%
void dfs(TreeNode *node, vector<vector<int>> &res, vector<int> &cur, int sum, int target) {
    if (!node) return ;
    sum += node->val;
    cur.push_back(node->val);
    if (!node->left && !node->right) {
        if (sum == target)
            res.push_back(cur);
    }
    if (node->left) dfs(node->left, res, cur, sum, target);
    if (node->right) dfs(node->right, res, cur, sum, target);
    cur.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(root, res, cur, 0, sum);
    return res;
}