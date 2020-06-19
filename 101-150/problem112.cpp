//
// Created by brayden on 2020-06-16.
//

#include "problem112.h"


// 86%， 47%
bool subsum(TreeNode *node, int cur_sum, int target) {
    if (!node) return false;
    cur_sum += node->val;
    if (!node->left && !node->right) return cur_sum == target;
    return subsum(node->left, cur_sum, target) || subsum(node->right, cur_sum, target);
}

bool hasPathSum2(TreeNode* root, int sum) {
    return subsum(root, 0, sum);
}

// less code

bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}