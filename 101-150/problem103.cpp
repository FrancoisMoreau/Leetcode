//
// Created by brayden on 2020-05-15.
//

#include "problem103.h"
#include <queue>

using std::vector;
using std::queue;

// My solution, used recursion
void subZigzag(vector<TreeNode *> nodes, vector<vector<int>> &res, bool left2right) {
    if (nodes.empty()) return;
    vector<TreeNode *> next;
    vector<int> cur;
    for (auto &i : nodes) {
        cur.push_back(i->val);
        if (i->left)
            next.push_back(i->left);
        if (i->right)
            next.push_back(i->right);
    }
    if (!left2right)
        std::reverse(cur.begin(), cur.end());
    res.push_back(cur);
    subZigzag(next, res, !left2right);
}

vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> res;
    subZigzag({root}, res, true);
    return res;
}

// Queue with iteration
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode *> nodeq;
    nodeq.push(root);
    bool left2right = true;
    while (!nodeq.empty()) {
        int cur_num = nodeq.size();
        vector<int> cur_lvl;
        for (int i = 0; i < cur_num; ++i) {
            cur_lvl.push_back(nodeq.front()->val);
            if (nodeq.front()->left)
                nodeq.push(nodeq.front()->left);
            if (nodeq.front()->right)
                nodeq.push(nodeq.front()->right);
            nodeq.pop();
        }
        if (!left2right)
            std::reverse(cur_lvl.begin(), cur_lvl.end());
        left2right = !left2right;
        res.push_back(cur_lvl);
    }
    return res;
}