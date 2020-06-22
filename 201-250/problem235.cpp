//
// Created by brayden on 2020-06-22.
//

#include "problem235.h"


// My solution, 40%, 20%
// Note that it's a BST here, but I didn't noticed and didn't use that
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    auto lhs = lowestCommonAncestor(root->left, p, q);
    auto rhs = lowestCommonAncestor(root->right, p, q);
    if (root == p || root == q || (lhs && rhs))  return root;
    else if (lhs) return lhs;
    else return rhs;
}


// Iteration, 70%, 50%
TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    while ((root->val - p->val) * (root->val - q->val) > 0)
        root = p->val < root->val ? root->left : root->right;
    return root;
}

// Recursion, 40%, 70%
TreeNode *lowestCommonAncestor3(TreeNode *root, TreeNode *p, TreeNode *q) {
    if ((root -> val > p -> val) && (root -> val > q -> val)) {
        return lowestCommonAncestor(root -> left, p, q);
    }
    if ((root -> val < p -> val) && (root -> val < q -> val)) {
        return lowestCommonAncestor(root -> right, p, q);
    }
    return root;
}