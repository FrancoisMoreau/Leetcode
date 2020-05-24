//
// Created by brayden on 2020-05-23.
//

#ifndef INC_351_400_PROBLEM352_H
#define INC_351_400_PROBLEM352_H

#include <vector>
#include <set>


class SummaryRanges2 {
public:
    /** Initialize your data structure here. */
    SummaryRanges2() = default;

    void addNum(int val) {
        inset.emplace(val);
    }

    std::vector<std::vector<int>> getIntervals();

private:
    std::set<int> inset;

};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() = default;

    void addNum(int val);

    std::vector<std::vector<int>> getIntervals() {
        std::vector<std::vector<int>> res;
        for (auto &i : inset)
            res.push_back({i.first, i.second});
        return res;
    }

private:
    std::set<std::pair<int, int>> inset;

};

void print(SummaryRanges &obj);
#endif //INC_351_400_PROBLEM352_H
