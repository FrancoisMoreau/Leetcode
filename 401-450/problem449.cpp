//
// Created by brayden on 2020-05-15.
//

#include "problem449.h"

using std::string;
using std::vector;

// My solution
/*
void Codec::subserialize(TreeNode *x, std::string &res) {
    if (!x) return;
    res += std::to_string(x->val) + ".";
    subserialize(x->left, res);
    subserialize(x->right, res);
}

string Codec::serialize(TreeNode *root) {
    string s;
    subserialize(root, s);
    printf("%s\n", s.c_str());
    return s;
}

TreeNode *Codec::deserialize(std::string data) {
    int pos = 0;
    vector<int> num;
    while ((pos = data.find('.')) != std::string::npos) {
        num.push_back(std::stoi(data.substr(0, pos)));
        data.erase(0, pos + 1);
    }
    TreeNode *root = subdeserialize(num, 0, num.size() - 1);
    return root;
}


TreeNode* Codec::subdeserialize(const std::vector<int> &num, int start, int end) {
    if (start > end) return nullptr;
    int upper = std::distance(num.begin(), std::upper_bound(num.begin() + start, num.begin() + end, num[start]));
    auto *x = new TreeNode(num[start]);
    ++start;
    x->left = subdeserialize(num, start, upper - 1);
    x->right = subdeserialize(num, upper + 1, end);
    return x;
}
 */

string Codec::serialize(TreeNode *root) {
    string s;
    subserialize(root, s);
    return s;
}

void Codec::subserialize(TreeNode *x, std::string &res){
    if (!x) return;
    char buf[4];
    memcpy(buf, &(x->val), sizeof(int));
    for (int i = 0; i < 4; ++i)
        res.push_back(buf[i]);
    subserialize(x->left, res);
    subserialize(x->right, res);
}

TreeNode *Codec::deserialize(std::string data) {
    int pos = 0;
    return subdeserialize(data, pos, INT_MIN, INT_MAX);
}

TreeNode *Codec::subdeserialize(const std::string &buf, int &pos, int minVal, int maxVal) {
    if (pos >= buf.size()) return nullptr;
    int val;
    memcpy(&val, &buf[pos], sizeof(int));
    if (val < minVal || val > maxVal) return nullptr;
    auto *x = new TreeNode(val);
    pos += sizeof(int);
    x->left = subdeserialize(buf, pos, minVal, val);
    x->right = subdeserialize(buf, pos, val, maxVal);
    return x;
}


