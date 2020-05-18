//
// Created by brayden on 2020-05-17.
//

#include "problem114.h"

// My solution
TreeNode *subflatten(TreeNode *root) {
    if (!root) return nullptr;
    if (root->left) {
        TreeNode *x = subflatten(root->left);
        x->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
    if (root->right) {
        return subflatten(root->right);
    } else {
        return root;
    }
}

void flatten2(TreeNode* root) {
    subflatten(root);
}

// another solution
TreeNode *flatten(TreeNode *root, TreeNode *pre) {
    if (root == nullptr) return  pre;
    pre = flatten(root->right, pre);
    pre = flatten(root->left, pre);
    root->right = pre;
    root->left = nullptr;
    pre = root;
    return pre;
}

void flatten(TreeNode *root) {
    flatten(root, nullptr);
}