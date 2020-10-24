//
// Created by brayden on 2020-10-21.
//

#ifndef INC_151_200_PROBLEM155_H
#define INC_151_200_PROBLEM155_H

#include <stack>
#include <set>

// C++, use stack + set, poor implementation!
// 2 stacks
// 1 stack

class MinStack2 {
public:
    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        stk1.push(x);
        if (stk2.empty() || x <= getMin()) stk2.push(x);
    }

    void pop() {
        if (stk1.top() == getMin()) stk2.pop();
        stk1.pop();
    }

    int top() {
        return stk1.top();
    }

    int getMin() {
        return stk2.top();
    }

private:
    std::stack<int> stk1, stk2;
};

class MinStack1{
public:
    MinStack1() {}
    void push(int x) {
        if (x <= min) {
            stk.push(min);
            min = x;
        }
        stk.push(x);
    }
    void pop() {
        if (stk.top() == min) {
            stk.pop();
            min = stk.top();
        }
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return min;
    }

private:
    int min = INT32_MAX;
    std::stack<int> stk;
};

class MinStack3{
public:
    MinStack3() {}
    void push(int x) {
        if (head == nullptr) {
            head = new Node(x, x);
        } else {
            head = new Node(x, std::min(x, head->min), head);
        }
    }
    void pop() {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
    int top() {
        return head->val;
    }
    int getMin() {
        return head->min;
    }

private:
    class Node {
    public:
        int val;
        int min;
        Node *next = nullptr;
        Node(int val, int min) : val(val), min(min) {}
        Node(int val, int min, Node *next) : val(val), min(min), next(next) {}
    };
    Node *head = nullptr;
};

#endif //INC_151_200_PROBLEM155_H
