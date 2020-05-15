//
// Created by brayden on 2020-05-14.
//

#ifndef INC_251_300_PROBLEM295_H
#define INC_251_300_PROBLEM295_H

#include <queue>
#include <vector>

class MedianFinder2 {
public:
    /** initialize your data structure here. */
    MedianFinder2() = default;

    void addNum(int num) {
        if (isEven) {
            mid = num;
            isEven = false;
            if (!minpq.empty()) {
                if (mid < maxpq.top()) {
                    mid = maxpq.top();
                    maxpq.pop();
                    maxpq.push(num);
                }
                if (mid > minpq.top()) {
                    mid = minpq.top();
                    minpq.pop();
                    minpq.push(num);
                }
            }
        } else {
            isEven = true;
            maxpq.push(std::min(mid, num));
            minpq.push(std::max(mid, num));
        }
    }

    double findMedian() {
        if (isEven)
            return float(maxpq.top() + minpq.top()) / 2;
        else
            return mid;
    }
private:
    bool isEven = true;
    int mid = 0;
    std::priority_queue<int> maxpq;
    std::priority_queue<int, std::vector<int>, std::greater<>> minpq;
};

class MedianFinder {
public:
    MedianFinder() = default;
    void addNum(int num) {
        if (!even) {
            maxpq.push(num);
            minpq.push(maxpq.top());
            maxpq.pop();
        } else {
            minpq.push(num);
            maxpq.push(minpq.top());
            minpq.pop();
        }
        even = !even;
    }
    double findMedian() {
        if (even)
            return float(maxpq.top() + minpq.top()) / 2;
        else
            return minpq.top();
    }
private:
    bool even = true;
    std::priority_queue<int> maxpq;
    std::priority_queue<int, std::vector<int>, std::greater<>> minpq;
};

#endif //INC_251_300_PROBLEM295_H
