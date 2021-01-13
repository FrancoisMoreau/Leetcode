//
// Created by brayden on 2020-10-25.
//

#ifndef INC_701_750_PROBLEM729_H
#define INC_701_750_PROBLEM729_H


#include <set>

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto next = intervals.lower_bound({start,end});
        if (next != intervals.end() && next->first < end) return false;
        if (next != intervals.begin() && (--next)->second < start) return false;
        intervals.insert({start, end});
        return true;
    }
private:
    std::set<std::pair<int, int>> intervals;
};



#endif //INC_701_750_PROBLEM729_H
