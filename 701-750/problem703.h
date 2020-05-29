//
// Created by brayden on 2020-05-15.
//

#ifndef INC_701_750_PROBLEM703_H
#define INC_701_750_PROBLEM703_H

#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums);

    int add(int val);
private:

    int K;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minpq;
// wrong!
//    std::priority_queue<int, std::vector<int>, std::greater<int>()> minpq;
};


#endif //INC_701_750_PROBLEM703_H
