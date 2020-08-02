//
// Created by brayden on 2020-05-27.
//

#include "problem297.h"

#include <string>

using std::string;

void sub_serialize(TreeNode *node, string &s) {
    if (!node) {
        s += "*";
        return;
    }
    s += std::to_string(node->val) + "*";
    sub_serialize(node->left, s);
    sub_serialize(node->right, s);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string res;
    sub_serialize(root, res);
    return res;
}

TreeNode *sub_deserialize(const string &data, int &pos) {
    if (data[pos] == '*') {
        ++pos;
        return nullptr;
    }
    int prev = pos;
    while (data[++pos] != '*') {}
    TreeNode *cur_node = new TreeNode(std::stoi(data.substr(prev, pos - prev)));
    ++pos;
    cur_node->left = sub_deserialize(data, pos);
    cur_node->right = sub_deserialize(data, pos);
    return cur_node;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    int pos = 0;
    return sub_deserialize(data, pos);
}