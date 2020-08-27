//
// Created by brayden on 2020-08-22.
//

#include "problem549.h"
#include <utility>
#include <algorithm>

using std::pair;

pair<int, int> subfind(TreeNode *node, int prev, int &maxlen) {
    if (!node) return {prev, prev};
    auto lhs = subfind(node->left, node->val, maxlen);
    auto rhs = subfind(node->right, node->val, maxlen);
    maxlen = std::max(std::max(lhs.second, rhs.second) - std::min(lhs.first, rhs.first) + 1, maxlen);
    if (prev - node->val == 1) {
        return {std::min(lhs.first, rhs.first), prev};
    } else if (node->val - prev == 1) {
        return {prev, std::max(lhs.second, rhs.second)};
    } else {
        return {prev, prev};
    }
}

int longestConsecutive2(TreeNode * root) {
    if (!root) return 0;
    int maxlen = 0;
    subfind(root, root->val, maxlen);
    return maxlen;
}