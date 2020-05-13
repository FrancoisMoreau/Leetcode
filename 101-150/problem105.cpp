//
// Created by brayden on 2020-05-11.
//

#include "problem105.h"

// My solution, poor performance
void buildChildren(vector<int> &preorder, vector<int> &inorder, TreeNode *x, int pre_idx, int in_idx, int in_right_range) {
    int lhs_idx = pre_idx + 1;
    int des_range = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.begin() + in_right_range, x->val));
    if (lhs_idx < preorder.size()) {
        int lhs_in_idx = std::find(inorder.begin(), inorder.begin() + in_idx, preorder[lhs_idx]) - inorder.begin();
        if (lhs_in_idx != in_idx) {
            TreeNode *lhs = new TreeNode(preorder[lhs_idx]);
            x->left = lhs;
            buildChildren(preorder, inorder, lhs, lhs_idx, lhs_in_idx, des_range);
        }
    }
    auto rhs_it = std::find_first_of(preorder.begin() + pre_idx, preorder.end(), inorder.begin() + in_idx, inorder.begin() + in_right_range);
    if (rhs_it != preorder.end()) {
        int rhs_idx = rhs_it - preorder.begin();
        TreeNode *rhs = new TreeNode(preorder[rhs_idx]);
        x->right = rhs;
        int rhs_in_idx = std::distance(inorder.begin(), std::find(inorder.begin() + in_idx, inorder.end(), preorder[rhs_idx]));
        buildChildren(preorder, inorder, rhs, rhs_idx, rhs_in_idx, in_right_range);
    }
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode *root = new TreeNode(preorder[0]);
    int in_idx = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), preorder[0]));
    buildChildren(preorder, inorder, root, 0, in_idx, inorder.size());
    return root;
}


// simpler version
// looks like binary search
// We can us hash to store the inorder position, so don't need to std::distance every time
TreeNode *helper(vector<int> &preorder, int &rootIndex, vector<int> &inorder, int start, int end) {
    if (rootIndex >= preorder.size() || start > end) return nullptr;
    auto *root = new TreeNode(preorder[rootIndex]);
    auto pos = std::distance(inorder.begin(), std::find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex]));
    ++rootIndex;
    root->left = helper(preorder, rootIndex, inorder, start, pos - 1);
    root->right = helper(preorder, rootIndex, inorder, pos + 1, end);
    return root;
}

TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
    int rootInex = 0;
    return helper(preorder, rootInex, inorder, 0, inorder.size() - 1);
}