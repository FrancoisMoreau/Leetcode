//
// Created by brayden on 2020-08-17.
//

#include "problem865.h"
#include <utility>

// My solution, 90%, 30%
int findheight(TreeNode *node, int height) {
    if (!node) return height;
    return std::max(findheight(node->left, height + 1), findheight(node->right, height + 1));
}

int findnode(TreeNode *node, int height, int max_height, TreeNode * &target) {
    if (!node) return height;
    int lhs = findnode(node->left, height + 1, max_height, target);
    int rhs = findnode(node->right, height + 1, max_height, target);
    if (lhs == max_height || rhs == max_height) {
        if (!target) target = node;
        if (lhs== max_height && rhs== max_height) target = node;

    }
    return std::max(lhs, rhs);
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int maxh = findheight(root, 0);
    TreeNode *res;
    findnode(root, 0, maxh, res);
    return res;
}

// One pass
std::pair<int, TreeNode *> deep(TreeNode *node) {
    if (!node) return {0, nullptr};
    std::pair<int, TreeNode *> lhs = deep(node->left);
    std::pair<int, TreeNode *> rhs = deep(node->right);


    int d1 = lhs.first, d2 = rhs.first;
    if (d1 == d2) {
        return {d1 + 1, node};
    } else if (d1 > d2)
        return {d1 + 1, lhs.second};
    else
        return {d2 + 1, rhs.second};
}

TreeNode* subtreeWithAllDeepest2(TreeNode *root) {
    return deep(root).second;
}