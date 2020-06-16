//
// Created by brayden on 2020-06-15.
//

#include "problem129.h"

// Recursion, 30%, 30%
int subcnt(TreeNode *node, int cur) {
    if (!node) return 0;
    cur = cur * 10 + node->val;
    if (!node->left && !node->right) return cur;
    return subcnt(node->left, cur) + subcnt(node->right, cur);
}

int sumNumbers(TreeNode* root) {
    return subcnt(root, 0);
}


// Iteration
