//
// Created by brayden on 2020-06-22.
//

#include "problem104.h"

// 99%, 70%
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return std::max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}
