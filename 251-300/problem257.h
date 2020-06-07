//
// Created by brayden on 2020-06-04.
//

#ifndef INC_251_300_PROBLEM257_H
#define INC_251_300_PROBLEM257_H

#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::string> binaryTreePaths(TreeNode* root);


#endif //INC_251_300_PROBLEM257_H
