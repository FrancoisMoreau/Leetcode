//
// Created by brayden on 2020-06-11.
//

#include "problem969.h"

using std::vector;

vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> res;
    for (int i = n ; i > 0; --i) {
        int dis = std::distance(A.begin(), std::find(A.begin(), A.begin() + i, i)) + 1;
        if (dis != i) {
            res.insert(res.end(), {dis, i});
            std::reverse(A.begin(), A.begin() + dis);
            std::reverse(A.begin(), A.begin() + i);
        }
    }
    return res;
}