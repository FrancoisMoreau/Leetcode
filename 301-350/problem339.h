//
// Created by brayden on 2020-08-24.
//

#ifndef INC_301_350_PROBLEM339_H
#define INC_301_350_PROBLEM339_H

#include <vector>

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const std::vector<NestedInteger> &getList() const;
};

int depthSum(const std::vector<NestedInteger>& nestedList);


#endif //INC_301_350_PROBLEM339_H
