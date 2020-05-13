//
// Created by brayden on 2020-05-12.
//

#ifndef INC_851_900_PROBLEM863_H
#define INC_851_900_PROBLEM863_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K);

#endif //INC_851_900_PROBLEM863_H
