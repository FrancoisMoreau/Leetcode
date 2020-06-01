//
// Created by brayden on 2020-05-31.
//

#ifndef INC_51_100_PROBLEM92_H
#define INC_51_100_PROBLEM92_H

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n);


#endif //INC_51_100_PROBLEM92_H
