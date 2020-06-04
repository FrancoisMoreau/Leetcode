//
// Created by brayden on 2020-06-03.
//

#include "problem515.h"

#include <unordered_map>

using std::unordered_map;
using std::vector;

// we can also use a vector here
void subcompare(TreeNode *node, unordered_map<int, int> &dict, int height) {
    if (!node) return;
    if (dict.find(height) == dict.end())
        dict[height] = node->val;
    else
        dict[height] = dict[height] > node->val ? dict[height] : node->val;
    subcompare(node->left, dict, height + 1);
    subcompare(node->right, dict, height + 1);
}

vector<int> largestValues(TreeNode* root) {
    unordered_map<int, int> dict;
    subcompare(root, dict, 0);
    vector<int> res(dict.size());
    for (int i = 0; i < res.size(); ++i) {
        res[i] = dict[i];
    }
    return res;
}