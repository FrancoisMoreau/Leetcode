//
// Created by brayden on 2020-05-15.
//

#ifndef INC_401_450_PROBLEM449_H
#define INC_401_450_PROBLEM449_H

#include <MacTypes.h>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data);

private:
    void subserialize(TreeNode *x, std::string &res);
    TreeNode *subdeserialize(const std::string &buf, int &pos, int minVal, int maxVal);
};

#endif //INC_401_450_PROBLEM449_H
