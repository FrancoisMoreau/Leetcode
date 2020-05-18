//
// Created by brayden on 2020-05-17.
//

#ifndef INC_201_250_PROBLEM222_H
#define INC_201_250_PROBLEM222_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root);

#endif //INC_201_250_PROBLEM222_H
