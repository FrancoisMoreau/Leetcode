//
// Created by brayden on 2020-05-12.
//

#include <vector>
#include "problem437.h"

#include <unordered_map>
using std::unordered_map;
using std::vector;

// My solution
/*
int subcnt(TreeNode *x, int sum, vector<int> prev_sum) {
    if (!x) return 0;
    for (auto &i : prev_sum)
        i += x->val;
    int cur = std::count(prev_sum.begin(), prev_sum.end(), sum);
    prev_sum.push_back(0);
    int lhs = subcnt(x->left, sum, prev_sum);
    int rhs = subcnt(x->right, sum, prev_sum);
    return lhs + rhs + cur;
}

int pathSum(TreeNode* root, int sum) {
    vector<int> prev_sum{0};
    return subcnt(root, sum, prev_sum);
}
*/

//O(n) solution, with hash

int findpathsum(TreeNode *x, int sum, int target, unordered_map<int, int> &presum) {
    if (!x) return 0;
    sum += x->val;
    int num_path2cur = presum[sum - target];
    ++presum[sum];
    int res = num_path2cur + findpathsum(x->left, sum, target, presum) +
            findpathsum(x->right, sum, target, presum);
    --presum[sum];
    return res;
}

int pathSum2(TreeNode *root, int sum) {
    if (!root) return 0;
    unordered_map<int, int> presum;
    presum[0] = 1;
    return  findpathsum(root, 0, sum, presum);
}

//DFS, O(n^2) worst in time, O(n) space
int sumup(TreeNode *x, int pre, int sum) {
    if (!x) return 0;
    int cur = pre + x->val;
    return (cur == sum) + sumup(x->left, cur, sum) + sumup(x->right, cur, sum);
}

int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;
    return sumup(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}
