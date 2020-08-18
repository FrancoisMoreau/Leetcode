//
// Created by brayden on 2020-08-16.
//

#include "problem270.h"
#include <numeric>


// iteration
int closestValue2(TreeNode * root, double target) {
    int res = root->val;
    while (root) {
        if (abs(res - target) >= abs(root->val - target))
            res = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return res;
}

// recursion
int closestValue(TreeNode *root, double target) {
    int a = root->val;
    TreeNode *t = target < a ? root->left : root->right;
    if (!t) return a;
    int b= closestValue(t, target);
    return abs(a - target ) < abs(b - target) ? a : b;
}