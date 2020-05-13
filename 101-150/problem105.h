//
// Created by brayden on 2020-05-11.
//

#ifndef INC_101_150_PROBLEM105_H
#define INC_101_150_PROBLEM105_H

#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

#endif //INC_101_150_PROBLEM105_H
