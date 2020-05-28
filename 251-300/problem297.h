//
// Created by brayden on 2020-05-27.
//

#ifndef INC_251_300_PROBLEM297_H
#define INC_251_300_PROBLEM297_H


#include <cstdio>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my code, 99%, 44%
class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string res;
        subserial(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int pos = 0;
        TreeNode *root = subdeserial(data, pos);
        return root;
    }

private:
    TreeNode* subdeserial(std::string &data, int &pos) {
        if (data[pos++] == '0' ) return nullptr;
        TreeNode *node = new TreeNode(0);
        memcpy(&node->val, data.data() + pos, sizeof(int));
        pos += 4;
        node->left = subdeserial(data, pos);
        node->right = subdeserial(data, pos);
        return node;
    }

    void subserial(TreeNode *node, std::string &res) {
        if (!node) {
            res += '0';
            return;
        }
        res.append("1");
        res.append(reinterpret_cast<const char*>(&node->val), sizeof(node->val));
        subserial(node->left, res);
        subserial(node->right, res);
    }
};

// using stringstream, use ' ' to output one word each time, amazing usage
class CodeC2{
public:
    std::string serialize(TreeNode *root) {
        std::ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode *deserialize(std::string data) {
        std::istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode *node, std::ostringstream &out) {
        if (node) {
            out << node->val << ' ';
            serialize(node->left, out);
            serialize(node->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode *deserialize(std::istringstream &in) {
        std::string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserialize(in);
        node->right = deserialize(in);
        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#endif //INC_251_300_PROBLEM297_H
