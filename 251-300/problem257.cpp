//
// Created by brayden on 2020-06-04.
//

#include "problem257.h"

using std::vector;
using std::string;
using std::to_string;

void subpath(TreeNode *node, string cur_path, vector<string> &path) {
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        path.emplace_back(cur_path + std::to_string(node->val));
        return;
    }
    subpath(node->left, cur_path + std::to_string(node->val) + "->", path);
    subpath(node->right, cur_path + std::to_string(node->val) + "->", path);

}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> path;
    string cur_path;
    subpath(root, cur_path, path);
    return path;
}

// better way, 82% (because of judgement of root)
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}