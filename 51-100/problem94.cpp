//
// Created by brayden on 2020-10-25.
//

#include "problem94.h"
#include <stack>


using std::vector;

// recursion, simple
void inorder(TreeNode *root, vector<int> &res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

std::vector<int> inorderTraversal(TreeNode* root) {
     vector<int> res;
     inorder(root, res);
     return res;
}

// iteration, be careful1
vector<int> inorderTraversal2(TreeNode* root) {
    std::stack<TreeNode *> stk;
    vector<int> res;
    while (root  || !stk.empty()) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

// Morris traversal
vector<int> inorderTraversal3(TreeNode* root) {
    vector<int> nodes;
    while (root) {
        if (root -> left) {
            TreeNode* pre = root -> left;
            while (pre -> right && pre -> right != root) {
                pre = pre -> right;
            }
            if (!pre -> right) {
                pre -> right = root;
                root = root -> left;
            } else {
                pre -> right = NULL;
                nodes.push_back(root -> val);
                root = root -> right;
            }
        } else {
            nodes.push_back(root -> val);
            root = root -> right;
        }
    }
    return nodes;
}