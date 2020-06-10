//
// Created by brayden on 2020-06-09.
//

#include "problem662.h"
#include <unordered_map>
#include <vector>
#include <queue>


using std::vector;
using std::unordered_map;

// I tried but didn't solve this problem at last
// The trick is, treat a BST as a binary heap
// DFS
void dfs(TreeNode *node, int id, int depth, vector<int> &lefts, int &maxWidth) {
    if (!node) return;
    if (depth >= lefts.size()) lefts.push_back(id);
    maxWidth = std::max(maxWidth, id + 1 - lefts[depth]);
    dfs(node->left, 2 * id, depth + 1, lefts, maxWidth);
    dfs(node->right, 2 * id + 1, depth + 1, lefts, maxWidth);
}

int widthOfBinaryTree(TreeNode* root) {
    vector<int> lefts;
    int maxWdith = 0;
    dfs(root, 0, 0, lefts, maxWdith);
    return maxWdith;
}

// BFS:
int widthOfBinaryTree2(TreeNode *root) {
    if (!root) return 0;
    int max = 0;
    std::queue<std::pair<TreeNode *, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        int lhs = q.front().second, rhs = lhs;
        for (int i = 0, n = q.size(); i < n; ++i)  {
            TreeNode *node = q.front().first;
            rhs = q.front().second;
            q.pop();
            if (node->left) q.push({node->left, rhs * 2});
            if (node->right) q.push({node->right, rhs * 2 + 1});
        }
        max = std::max(max, rhs - lhs + 1);
    }
    return max;
}


// to pass the last test case:
int widthOfBinaryTree3(TreeNode *root) {
    if (!root) return 0;
    int max = 0;
    std::queue<std::pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int n = q.size();
        int offset = q.front().second;
        max = std::max(max, q.back().second - q.front().second + 1);
        for (int i = 0; i < n; ++i) {
            auto node = q.front().first;
            if (node->left) q.push({node->left, 2 * (q.front().second - offset)});
            if (node->right) q.push({node->right, 2 * (q.front().second - offset) + 1});
            q.pop();
        }
    }
    return max;
}
