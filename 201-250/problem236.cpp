//
// Created by brayden on 2020-06-02.
//

#include "problem236.h"

// My solution, 85%, 100%
bool subsearch(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode *(&target)) {
    if (!node) return false;
    // cannot add follow line
    // if (target) return true;
    // because if we add it, if the lhs has the target,
    // then the rhs will also return true, which results in highest node
    bool cur = node->val == p->val || node->val == q->val;
    bool lhs = subsearch(node->left, p, q, target);
    bool rhs = subsearch(node->right, p, q, target);
    if ((cur && lhs) || (cur && rhs) || (lhs && rhs)) {
        target = node;
        return true;
    }
    return cur || lhs || rhs;
}

TreeNode* lowestCommonAncestor4(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *target = nullptr;
    subsearch(root, p, q, target);
    return  target;
}

// simpler ans
TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) return root;
    TreeNode *lhs = lowestCommonAncestor2(root->left, p, q);
    TreeNode *rhs = lowestCommonAncestor2(root->right, p, q);
    if (lhs && rhs) return root;
    return lhs ? lhs : rhs;

}