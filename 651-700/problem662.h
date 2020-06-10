//
// Created by brayden on 2020-06-09.
//

#ifndef INC_651_700_PROBLEM662_H
#define INC_651_700_PROBLEM662_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root);


#endif //INC_651_700_PROBLEM662_H
