//
// Created by brayden on 2020-05-27.
//

#include "problem543.h"
#include <algorithm>

int cur_len(TreeNode *node, int &max) {
    if (!node) return 0;
    int lhs = cur_len(node->left,max);
    int rhs = cur_len(node->right, max);
    max = std::max(lhs + rhs + 1, max);
    return std::max(lhs, rhs) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int max = 0;
    cur_len(root, max);
    return max > 1 ? max - 1 : 0;
}

// directly
int rec(TreeNode* root, int &d) {
    if(root == NULL) return 0;
    int ld = rec(root->left, d);
    int rd = rec(root->right, d);
    d=std::max(d,ld+rd);
    return std::max(ld,rd)+1;
}

int diameterOfBinaryTree2(TreeNode* root) {
    int d=0;
    rec(root, d);
    return d;
}

