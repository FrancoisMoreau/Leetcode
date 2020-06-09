//
// Created by brayden on 2020-06-08.
//

#ifndef INC_601_650_PROBLEM622_H
#define INC_601_650_PROBLEM622_H

#include <vector>

// easy to implement if we can use deque


class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : vec(k) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        else {
            tail = (tail + 1) % vec.size();
            vec[tail] = value;
            ++count;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        else {
            head = (head + 1) % vec.size();
            --count;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : vec[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : vec[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return vec.size() == count;
    }

private:
    std::vector<int> vec;
    int count = 0;
    int head = 0, tail = -1;
};


#endif //INC_601_650_PROBLEM622_H
