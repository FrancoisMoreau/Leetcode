//
// Created by brayden on 2020-05-31.
//

#include <climits>
#include <cstdio>
#include "problem98.h"


// My solution
bool isValid(TreeNode *node, long min, long max) {
    if (!node) return true;
    if (node->val >= max || node->val <= min) return false;
    if (!isValid(node->left, min, node->val) || !isValid(node->right, node->val, max))
        return false;
    return true;
}

bool isValidBST(TreeNode* root) {
    return isValid(root, long(INT_MIN) - 100, long(INT_MAX) + 100);
}

// We can also use node pointer to avoid using long
bool isValidBST2(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST2(root->left, minNode, root) && isValidBST2(root->right, root, maxNode);
}

bool isValidBST2(TreeNode* root) {
    return isValidBST2(root, nullptr, nullptr);
}

// iterative inorder trave
//public boolean isValidBST(TreeNode root) {
//    if (root == null) return true;
//    Stack<TreeNode> stack = new Stack<>();
//    TreeNode pre = null;
//    while (root != null || !stack.isEmpty()) {
//        while (root != null) {
//            stack.push(root);
//            root = root.left;
//        }
//        root = stack.pop();
//        if(pre != null && root.val <= pre.val) return false;
//        pre = root;
//        root = root.right;
//    }
//    return true;
//}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == nullptr) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};