#include <iostream>
#include <vector>


#include "cutoff_rank.h"
#include "laboratory.h"
#include "earliest_time.h"
#include "LRUcache.h"
#include "gateway.h"
#include "rearrange_string.h"
#include "stock_price.h"
#include "two_sum_pair.h"
#include "slowest_key.h"
#include "substring_pattern.h"
#include "highest_profit.h"
#include "getStrictIncreaseDecrease.h"

using namespace std;

struct TreeNode {
         int val;
        TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool sub_check(TreeNode *s, TreeNode *t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val == t->val) return sub_check(s->left, t->left) && sub_check(s->right, t->right);
    else return false;
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (sub_check(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);

}


int main() {
    std::cout << "Cut off rank: \n";
    vector<int> input_cutoff_1{100, 50, 50, 25};
    vector<int> input_cutoff_2{2, 2, 3, 4, 5};
    cout << cutoff_rank(3, input_cutoff_1) << endl;
    cout << cutoff_rank(4, input_cutoff_2) << endl;

    std::cout << "\nLaboratory: \n";
    vector<int> input_requirements{4, 6, 6, 7};
    vector<vector<int>> input_markings{{0, 3}, {0, 5}, {0, 7}, {1, 6}, {1, 8}, {1, 9}, {2, 3}, {2, 5}, {2, 6}};
    cout << laboratory(input_requirements, 3, input_markings) << endl;

    std::cout << "\n\nearliest time: \n";
    vector<int> input_buildopen{8, 10};
    vector<int> offloadtime{2, 2, 3, 1, 8, 7, 4, 5};
    cout << earliest_time(2, input_buildopen, offloadtime) << endl;

    std::cout << "\n\nLRU cache: \n";
    vector<int> input_page{1, 2, 1, 3, 1, 2};
    cout << lruCacheMisses(input_page, 2);

    std::cout << "\n\nGateway: \n";
    vector<int> input_gateway{1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11};
    cout << gateway(input_gateway) << endl;

    cout << "\n\nRearrange String: \n";
    string input_rearrange = "zzzzzzxxxzzaabbazza";
    cout << rearrange_string(input_rearrange, 3) << endl;

    cout << "\n\nStock Price: \n";
    vector<int> input_stockprice{4, 2, 12, 11, -5};
    vector<int> res_stockprice = min_stock_price(input_stockprice, 2);
    for (int i : res_stockprice)
        cout << i << ", ";
    cout << "\n\n";

    cout << "\n\nUnique two pair sum: \n";
    vector<int> input_twosum{5, 7, 9, 13, 11, 6, 6, 3, 3};
    cout << uniquePairs(input_twosum, 12) << endl;

    cout << "\n\nslowest key: \n";
    vector<vector<int>> input_slowestkey{{0, 2}, {1, 5}, {0, 9}, {2, 15}};
    cout << slowestkey(input_slowestkey) << endl;

    cout << "\n\nsubstring pattern: \n";
    string input_divisor{"lrbblrbb"}, input_divident{"lrbb"};
    cout << substring_pattern(input_divisor, input_divident) << endl;

    cout << "\n\nhighest profit: \n";
    vector<int> input_inventory{3, 5};
    cout << max_supply_profit(2, input_inventory, 6) << endl;

    return 0;
}