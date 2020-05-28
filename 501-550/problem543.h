//
// Created by brayden on 2020-05-27.
//

#ifndef INC_501_550_PROBLEM543_H
#define INC_501_550_PROBLEM543_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int diameterOfBinaryTree(TreeNode* root);

#endif //INC_501_550_PROBLEM543_H
