//
// Created by brayden on 2019-09-27.
//

#ifndef PROBLEM33_ROTATEDARRAYSEARCH_H
#define PROBLEM33_ROTATEDARRAYSEARCH_H

#include <vector>

class RotatedArraySearch {
private:
    int find_pivot(std::vector<int> &nums, int left, int right);
public:
    int search(std::vector<int>& nums, int target);

};


#endif //PROBLEM33_ROTATEDARRAYSEARCH_H
