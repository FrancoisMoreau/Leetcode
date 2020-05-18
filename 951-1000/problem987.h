//
// Created by brayden on 2020-05-17.
//

#ifndef INC_951_1000_PROBLEM987_H
#define INC_951_1000_PROBLEM987_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> verticalTraversal(TreeNode* root);


#endif //INC_951_1000_PROBLEM987_H
