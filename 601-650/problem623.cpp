//
// Created by brayden on 2020-10-27.
//

#include "problem623.h"


TreeNode *construct(TreeNode *root, int v, int d, bool isleft) {
    if (d == 1) {
        TreeNode *node = new TreeNode(v);
        if (isleft) node->left = root;
        else node->right = root;
        return node;
    }
    if (!root) return nullptr;
    root->left = construct(root->left, v, d - 1, true);
    root->right = construct(root->right, v, d - 1, false);
    return root;
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    return construct(root, v, d, true);
}