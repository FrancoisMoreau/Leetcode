//
// Created by brayden on 2020-05-14.
//

#ifndef INC_1_50_PROBLEM23_H
#define INC_1_50_PROBLEM23_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists);

#endif //INC_1_50_PROBLEM23_H
