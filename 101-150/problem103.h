//
// Created by brayden on 2020-05-15.
//

#ifndef INC_101_150_PROBLEM103_H
#define INC_101_150_PROBLEM103_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);


#endif //INC_101_150_PROBLEM103_H
