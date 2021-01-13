//
// Created by brayden on 1/5/21.
//

#ifndef NVIDIA_SPARSEVEC_H
#define NVIDIA_SPARSEVEC_H

#include <utility>
#include <vector>

class SparseVec {
public:
    SparseVec(std::initializer_list<int> il) {
        int idx = 0;
       for (auto beg = il.begin(); beg != il.end(); ++beg, ++idx) {
           vec.emplace_back(idx, *beg);
       }
    }

    int operator*(SparseVec &rhs) {
        auto left = vec.begin(), right = rhs.vec.begin();
        int total = 0;
        while (left != vec.end() && right != rhs.vec.end()) {
            if (left->first < right->first) left++;
            else if (right->first < left->first) right++;
            else {
                total += left->second * right->second;
                left++;
                right++;
            }
        }
        return total;
    }

private:
    std::vector<std::pair<int, int>> vec;

};


#endif //NVIDIA_SPARSEVEC_H
