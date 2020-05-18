//
// Created by brayden on 2020-05-17.
//

#include <cmath>
#include "problem222.h"

// My naive solution, time: O(n)
int naive_count(TreeNode *root) {
    if (!root) return 0;
    return naive_count(root->left) + naive_count(root->right) + 1;
}

int countNodes2(TreeNode* root) {
    return naive_count(root);
}


// better way: O(logN * logN)
//int countNodes(TreeNode *root) {
//    if (!root) return 0;
//    int lhs_h = 0, rhs_h = 0;
//    TreeNode *lhs = root, *rhs = root;
//    while (lhs) {
//        ++lhs_h;
//        lhs = lhs->left;
//    }
//    while (rhs) {
//        ++rhs_h;
//        rhs = rhs->right;
//    }
//    if (lhs_h == rhs_h) return pow(2, lhs_h) - 1;
//    return 1 + countNodes(root->left) + countNodes(root->right);
//}

// recursion
int height(TreeNode *root) {
    return !root? -1 : 1 + height(root->left);
}

int countNodes(TreeNode *root) {
    int h = height(root);
    return h < 0 ? 0 : height(root->right) == h - 1 ?
    (1 << h) + countNodes(root->right) : (1 << h - 1) + countNodes(root->left);
}