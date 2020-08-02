//
// Created by brayden on 2020-05-11.
//

#include "problem124.h"
#include <utility>

using std::pair;

// My solution, time: 24%, 68%, 80%, not stable, space: 6%
pair<int, int> subMax(TreeNode *x, int &max) {
    if (!x) return {std::min(max, 0), std::min(max, 0)};
    auto lhs = subMax(x->left, max);
    auto rhs = subMax(x->right, max);
    int first = std::max(std::max(lhs.first, rhs.first), 0) + x->val;
    max = std::max(first, max);
    int second = std::max( std::max(lhs.first + rhs.first, 0)+ x->val, std::max(lhs.second, rhs.second));
    return {first, second};
}

int maxPathSum2(TreeNode* root) {
    int max = root->val;
    auto  res = subMax(root, max);
    return std::max(max, std::max(res.first, res.second));
}

// Simpler
// Main idea is similar, but more concise because use my "max" to store max left-currentnode-right instead

int maxPathDown(TreeNode *x, int &max) {
    if (!x) return 0;
    int left = std::max(0, maxPathDown(x->left, max));
    int right = std::max(0, maxPathDown(x->right, max));
    max = std::max(max, left + right + x->val);
    return std::max(left, right) + x->val;
}

int maxPathSum(TreeNode *root) {
    int max = INT_MIN;
    maxPathDown(root, max);
    return max;
}

// My solution after 2 month, 75%, 77%
int dfs(TreeNode *node, int &cur_max) {
    if (!node) return 0;
    int lhs = dfs(node->left, cur_max);
    int rhs = dfs(node->right, cur_max);
    cur_max = std::max(cur_max, lhs + rhs + node->val);
    return std::max(std::max(lhs, rhs) + node->val, 0);
}

int maxPathSum3(TreeNode* root) {
    if (!root) return 0;
    int cur_max = root->val;
    dfs(root, cur_max);
    return cur_max;
}