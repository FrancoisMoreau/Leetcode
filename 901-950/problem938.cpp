//
// Created by brayden on 2020-05-29.
//

#include "problem938.h"
#include <stack>

// 25%, 5%
int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) return 0;
    if (root->val > R) return rangeSumBST(root->left, L, R);
    else if (root->val < L) return rangeSumBST(root->right, L, R);
    else {
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}

// similar peformance
// iteration
int rangeSumBST2(TreeNode *root, int L, int R) {
    std::stack<TreeNode *> stk;
    stk.push(root);
    int sum = 0;
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();
        if (!node) continue;
        if (node->val > L) stk.push(node->left);
        if (node->val < R) stk.push(node->right);
        if (node->val <= R && node->val >= L) sum+= node->val;

    }
    return sum;
}